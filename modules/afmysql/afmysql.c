#include "afmysql.h"

#ifdef ENABLE_MYSQL

#include "logqueue.h"
#include "templates.h"
#include "messages.h"
#include "misc.h"
#include "stats.h"
#include "apphook.h"
#include "timeutils.h"

#include <string.h>
#include <mysql.h>

#if ENABLE_SSL
#include <openssl/md5.h>
#endif

/* field flags */
enum
{
  AFMYSQL_FF_DEFAULT = 0x0001,
};

/* destination driver flags */
enum
{
  AFMYSQL_DDF_EXPLICIT_COMMITS = 0x0001,
  AFMYSQL_DDF_DONT_CREATE_TABLES = 0x0002,
};

typedef struct _AFMYSqlField
{
  guint32 flags;
  gchar *name;
  gchar *type;
  LogTemplate *value;
} AFMYSqlField;

typedef void * mysql_result;
/**
 * AFSqlDestDriver:
 *
 * This structure encapsulates an SQL destination driver. SQL insert
 * statements are generated from a separate thread because of the blocking
 * nature of the DBI API. It is ensured that while the thread is running,
 * the reference count to the driver structure is increased, thus the db
 * thread can read any of the fields in this structure. To do anything more
 * than simple reading out a value, some kind of locking mechanism shall be
 * used.
 **/
typedef struct _AFMYSqlDestDriver
{
  LogDestDriver super;
  /* read by the db thread */
  gchar *type;
  gchar *host;
  gchar *port;
  gchar *user;
  gchar *password;
  gchar *database;
  gchar *encoding;
  GList *columns;
  GList *values;
  GList *indexes;
  LogTemplate *table;
  gint fields_len;
  AFMYSqlField *fields;
  gchar *null_value;
  gint time_reopen;
  gint num_retries;
  gint flush_lines;
  gint flush_timeout;
  gint flush_lines_queued;
  gint flags;
  GList *session_statements;

  LogTemplateOptions template_options;

  StatsCounterItem *dropped_messages;
  StatsCounterItem *stored_messages;

  GHashTable *dbd_options;
  GHashTable *dbd_options_numeric;

  /* shared by the main/db thread */
  GThread *db_thread;
  GMutex *db_thread_mutex;
  GCond *db_thread_wakeup_cond;
  gboolean db_thread_terminate;
  gboolean db_thread_suspended;
  GTimeVal db_thread_suspend_target;
  LogQueue *queue;
  /* used exclusively by the db thread */
  gint32 seq_num;
  GHashTable *validated_tables;
  guint32 failed_message_counter;

  MYSQL *mysql;
} AFMYSqlDestDriver;


#define MAX_FAILED_ATTEMPTS 3

void
afmysql_dd_add_dbd_option(LogDriver *s, const gchar *name, const gchar *value)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  g_hash_table_insert(self->dbd_options, g_strdup(name), g_strdup(value));
}

void
afmysql_dd_add_dbd_option_numeric(LogDriver *s, const gchar *name, gint value)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  g_hash_table_insert(self->dbd_options_numeric, g_strdup(name), GINT_TO_POINTER(value));
}

void
afmysql_dd_set_host(LogDriver *s, const gchar *host)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  g_free(self->host);
  self->host = g_strdup(host);
}

gboolean afmysql_dd_check_port(const gchar *port)
{
  /* only digits (->numbers) are allowed */
  int len = strlen(port);
  for (int i = 0; i < len; ++i)
    if (port[i] < '0' || port[i] > '9')
    {
      return FALSE;
    }
  return TRUE;
}

void
afmysql_dd_set_port(LogDriver *s, const gchar *port)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  g_free(self->port);
  self->port = g_strdup(port);
}

void
afmysql_dd_set_user(LogDriver *s, const gchar *user)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  g_free(self->user);
  self->user = g_strdup(user);
}

void
afmysql_dd_set_password(LogDriver *s, const gchar *password)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  g_free(self->password);
  self->password = g_strdup(password);
}

void
afmysql_dd_set_database(LogDriver *s, const gchar *database)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  g_free(self->database);
  self->database = g_strdup(database);
}

void
afmysql_dd_set_table(LogDriver *s, const gchar *table)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  log_template_compile(self->table, table, NULL);
  printf("table: %s\n", self -> table);
}

void
afmysql_dd_set_columns(LogDriver *s, GList *columns)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  string_list_free(self->columns);
  self->columns = columns;
}

void
afmysql_dd_set_indexes(LogDriver *s, GList *indexes)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  string_list_free(self->indexes);
  self->indexes = indexes;
}

void
afmysql_dd_set_values(LogDriver *s, GList *values)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  string_list_free(self->values);
  self->values = values;
}

void
afmysql_dd_set_null_value(LogDriver *s, const gchar *null)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  if (self->null_value)
    g_free(self->null_value);
  self->null_value = g_strdup(null);
}

void
afmysql_dd_set_retries(LogDriver *s, gint num_retries)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  if (num_retries < 1)
    {
      self->num_retries = 1;
    }
  else
    {
      self->num_retries = num_retries;
    }
}

void
afmysql_dd_set_frac_digits(LogDriver *s, gint frac_digits)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  self->template_options.frac_digits = frac_digits;
}

void
afmysql_dd_set_send_time_zone(LogDriver *s, const gchar *send_time_zone)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  self->template_options.time_zone[LTZ_SEND] = g_strdup(send_time_zone);
}

void
afmysql_dd_set_local_time_zone(LogDriver *s, const gchar *local_time_zone)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  self->template_options.time_zone[LTZ_LOCAL] = g_strdup(local_time_zone);
}

void
afmysql_dd_set_flush_lines(LogDriver *s, gint flush_lines)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  self->flush_lines = flush_lines;
}

void
afmysql_dd_set_flush_timeout(LogDriver *s, gint flush_timeout)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  self->flush_timeout = flush_timeout;
}

void
afmysql_dd_set_session_statements(LogDriver *s, GList *session_statements)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  self->session_statements = session_statements;
}

void
afmysql_dd_set_flags(LogDriver *s, gint flags)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  self->flags = flags;
}

/**
 * afmysql_dd_run_query:
 *
 * Run an MYSQL query on the connected database.
 *
 * NOTE: This function can only be called from the database thread.
 **/
static gboolean
afmysql_dd_run_query(AFMYSqlDestDriver *self, const gchar *query)
{
  msg_debug("Running MYSQL query",
            evt_tag_str("query", query),
            NULL);

  const gchar *db_error;

  if(mysql_query(self->mysql, query))
     {
          db_error = mysql_error(self->mysql);
          msg_error("Error running MYSQL query",
                    evt_tag_str("host", self->host),
                    evt_tag_str("port", self->port),
                    evt_tag_str("user", self->user),
                    evt_tag_str("database", self->database),
                    evt_tag_str("error", db_error),
                    evt_tag_str("query", query),
                    NULL);
       return FALSE;
     }
  msg_debug("MYSQL query successfully runned",
            evt_tag_str("query", query),
            NULL);
  return TRUE;
}

static gboolean
afmysql_dd_check_sql_identifier(gchar *token, gboolean sanitize)
{
  gint i;

  for (i = 0; token[i]; i++)
    {
      if (!((token[i] == '.') || (token[i] == '_') || (i && token[i] >= '0' && token[i] <= '9') || (g_ascii_tolower(token[i]) >= 'a' && g_ascii_tolower(token[i]) <= 'z')))
        {
          if (sanitize)
            token[i] = '_';
          else
            return FALSE;
        }
    }
  return TRUE;
}
/**
 * afsql_dd_create_index:
 *
 * This function creates an index for the column specified and returns
 * TRUE to indicate success.
 *
 * NOTE: This function can only be called from the database thread.
 **/
static gboolean
afmysql_dd_create_index(AFMYSqlDestDriver *self, gchar *table, gchar *column)
{
  /**/
}

/**
 * afsql_dd_validate_table:
 *
 * Check if the given table exists in the database. If it doesn't
 * create it, if it does, check if all the required fields are
 * present and create them if they don't.
 *
 * NOTE: This function can only be called from the database thread.
 **/
static GString *
afmysql_dd_validate_table(AFMYSqlDestDriver *self, LogMessage *msg)
{
  GString *query_string, *table;
  gboolean success = FALSE;
  gint i;

  table = g_string_sized_new(32);
  log_template_format(self->table, msg, &self->template_options, LTZ_LOCAL, 0, NULL, table);

  if (self->flags & AFMYSQL_DDF_DONT_CREATE_TABLES)
    return table;

  afmysql_dd_check_sql_identifier(table->str, TRUE);

  if (g_hash_table_lookup(self->validated_tables, table->str))
    return table;

  query_string = g_string_sized_new(512);

  g_string_printf(query_string, "CREATE TABLE IF NOT EXISTS %s.%s(", self -> user, table -> str);
  for (i = 0; i < self->fields_len; i++)
        {
          g_string_append_printf(query_string, "%s %s", self->fields[i].name, self->fields[i].type);
          if (i != self->fields_len - 1)
            g_string_append(query_string, ", ");
        }
  g_string_append(query_string, ");");
  if(!afmysql_dd_run_query( self, query_string -> str))
    {
       msg_error("Error creating table, giving up",
                    evt_tag_str("table", table->str),
                    NULL);
    }

}

/**
 * afsql_dd_begin_txn:
 *
 * Begin SQL transaction.
 *
 * NOTE: This function can only be called from the database thread.
 **/
static gboolean
afmysql_dd_begin_txn(AFMYSqlDestDriver *self)
{
  // Set autocommit mode on if 1, off if 0
  if(mysql_autocommit(self -> mysql, 1))
  {
    msg_error("Error begin txn",
                    evt_tag_str("Error", mysql_error(self -> mysql)),
                    NULL);
    return FALSE;
  }
  return TRUE;
}

/**
 * afsql_dd_begin_txn:
 *
 * Commit SQL transaction.
 *
 * NOTE: This function can only be called from the database thread.
 **/
static gboolean
afmysql_dd_commit_txn(AFMYSqlDestDriver *self)
{
  if(mysql_commit(self -> mysql))
  {
    msg_error("Error commit txn",
                     evt_tag_str("Error:", mysql_error(self -> mysql)),
		     NULL);
    return FALSE;
  }
  return TRUE;
}

/**
 * afsql_dd_suspend:
 * timeout: in milliseconds
 *
 * This function is assumed to be called from the database thread
 * only!
 **/
static void
afmysql_dd_suspend(AFMYSqlDestDriver *self)
{
  self->db_thread_suspended = TRUE;
  g_get_current_time(&self->db_thread_suspend_target);
  g_time_val_add(&self->db_thread_suspend_target, self->time_reopen * 1000 * 1000); /* the timeout expects microseconds */
}

static void
afmysql_dd_disconnect(AFMYSqlDestDriver *self)
{
  mysql_close(self -> mysql);
  msg_debug("MYSQL disconnected",
            NULL);
  
}

static void
afmysql_dd_set_dbd_opt(gpointer key, gpointer value, gpointer user_data)
{
  /* */
}

static void
afmysql_dd_set_dbd_opt_numeric(gpointer key, gpointer value, gpointer user_data)
{
  /*b */
}

static gboolean
afmysql_dd_connect(AFMYSqlDestDriver *self)
{
 printf("\nbegin dd_cnnect\n");
 self -> mysql = mysql_init(NULL);
 if(!mysql_real_connect(self -> mysql, self -> host, self -> user, self -> password, self -> database, self -> port,NULL,0))
 {
   msg_error("Error establishing MYSQL connection",
                evt_tag_str("type", self->type),
                evt_tag_str("host", self->host),
                evt_tag_str("port", self->port),
                evt_tag_str("username", self->user),
                evt_tag_str("database", self->database),
                evt_tag_str("error", mysql_error(self -> mysql)),
                NULL);
   return FALSE;
 }
 return TRUE;
}

static gboolean
afmysql_dd_insert_fail_handler(AFMYSqlDestDriver *self, LogMessage *msg,
                             LogPathOptions *path_options)
{
  if (self->failed_message_counter < self->num_retries - 1)
    {
      log_queue_push_head(self->queue, msg, path_options);

      /* database connection status sanity check after failed query */
      if (mysql_ping(self->mysql) != 0)
        {
          msg_error("Error, no MYSQL connection after failed query attempt",
                    evt_tag_str("type", self->type),
                    evt_tag_str("host", self->host),
                    evt_tag_str("port", self->port),
                    evt_tag_str("username", self->user),
                    evt_tag_str("database", self->database),
                    evt_tag_str("error", mysql_error(self -> mysql)),
                    NULL);
          return FALSE;
        }

      self->failed_message_counter++;
      return FALSE;
    }
  msg_error("Multiple failures while inserting this record into the database, message dropped",
            evt_tag_int("attempts", self->num_retries),
            NULL);
  stats_counter_inc(self->dropped_messages);
  log_msg_drop(msg, path_options);
  self->failed_message_counter = 0;
  return TRUE;
}

static GString *
afmysql_dd_construct_query(AFMYSqlDestDriver *self, GString *table,
                         LogMessage *msg)
{
 GString *value;
  GString *query_string;
  gint i;

  value = g_string_sized_new(256);
  query_string = g_string_sized_new(512);

  g_string_printf(query_string, "INSERT INTO %s VALUES(", "messages");
  for (i = 0; i < self->fields_len; i++)
    {

      if (self->fields[i].value == NULL)
        {
          /* the config used the 'default' value for this column -> the fields[i].value is NULL, use SQL default */
          g_string_append(query_string, "DEFAULT");
        }
      else
        {
          log_template_format(self->fields[i].value, msg, &self->template_options, LTZ_SEND, self->seq_num, NULL, value);

          if (self->null_value && strcmp(self->null_value, value->str) == 0)
            {
              g_string_append(query_string, "NULL");
            }
          else
            {
	      g_string_append(query_string,g_strdup_printf("'%s'", value -> str));
              
            }
        }

      if (i != self->fields_len - 1)
        g_string_append(query_string, ", ");
    }
  g_string_append(query_string, ");");
  fprintf(stderr, query_string);
  g_string_free(value, TRUE);

  return query_string;
}

/**
 * afsql_dd_insert_db:
 *
 * This function is running in the database thread
 *
 * Returns: FALSE to indicate that the connection should be closed and
 * this destination suspended for time_reopen() time.
 **/
static gboolean
afmysql_dd_insert_db(AFMYSqlDestDriver *self)
{
  msg_debug("Begin afmysql_dd_insert_db",
            NULL);
  GString *table, *query_string;
  LogMessage *msg;
  gboolean success;
  LogPathOptions path_options = LOG_PATH_OPTIONS_INIT;

  afmysql_dd_connect(self);

  success = log_queue_pop_head(self->queue, &msg, &path_options, FALSE, FALSE);
  if (!success)
    return TRUE;

  msg_set_context(msg);

  table = afmysql_dd_validate_table(self, msg);
  if (!table)
    {
      // If validate table is FALSE then close the connection and wait time_reopen time (next call)
      msg_error("Error checking table, disconnecting from database, trying again shortly",
                evt_tag_int("time_reopen", self->time_reopen),
                NULL);
      msg_set_context(NULL);
      g_string_free(table, TRUE);
      return FALSE;//afmysql_dd_insert_fail_handler(self, msg, &path_options);
    }

  query_string = afmysql_dd_construct_query(self, table, msg);
  self -> flush_lines_queued = -1;
  if (self->flush_lines_queued == 0 /*&& !afmysql_dd_begin_txn(self)*/)
    return FALSE;

  success = afmysql_dd_run_query(self, query_string->str);

  if (success && self->flush_lines_queued != -1)
    {
      self->flush_lines_queued++;
      if (self->flush_lines && self->flush_lines_queued == self->flush_lines && !afmysql_dd_commit_txn(self))
        return FALSE;
    }
  //g_string_free(table, TRUE);
  g_string_free(query_string, TRUE);

  msg_set_context(NULL);

  /*if (!success)
    return afmysql_dd_insert_fail_handler(self, msg, &path_options);*/

  /* we only ACK if each INSERT is a separate transaction */
  if ((self->flags & AFMYSQL_DDF_EXPLICIT_COMMITS) == 0)
    log_msg_ack(msg, &path_options);
  log_msg_unref(msg);
  step_sequence_number(&self->seq_num);
  self->failed_message_counter = 0;
  msg_debug("Successfully finished afmysql_dd_insert_db",
            NULL);
  return TRUE;
}


static void
afmysql_dd_message_became_available_in_the_queue(gpointer user_data)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) user_data;

  g_mutex_lock(self->db_thread_mutex);
  g_cond_signal(self->db_thread_wakeup_cond);
  g_mutex_unlock(self->db_thread_mutex);
}

/* assumes that db_thread_mutex is held */
static void
afmysql_dd_wait_for_suspension_wakeup(AFMYSqlDestDriver *self)
{
 if (!self->db_thread_terminate)
    g_cond_timed_wait(self->db_thread_wakeup_cond, self->db_thread_mutex, &self->db_thread_suspend_target);
  self->db_thread_suspended = FALSE;
}

/**
 * afsql_dd_database_thread:
 *
 * This is the thread inserting records into the database.
 **/
static gpointer
afmysql_dd_database_thread(gpointer arg)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) arg;

  msg_verbose("Database thread started",
              evt_tag_str("driver", self->super.super.id),
              NULL);
  while (!self->db_thread_terminate)
    {
      g_mutex_lock(self->db_thread_mutex);
      if (self->db_thread_suspended)
        {
          afmysql_dd_wait_for_suspension_wakeup(self);
          /* we loop back to check if the thread was requested to terminate */
        }
      else if (!log_queue_check_items(self->queue, NULL, afmysql_dd_message_became_available_in_the_queue, self, NULL))
        {
          /* we have nothing to INSERT into the database, let's wait we get some new stuff */
           printf("\nnothing to insert\n");
          if (self->flush_lines_queued > 0)
            {
              if (!afmysql_dd_commit_txn(self))
                {
                  afmysql_dd_disconnect(self);
                  afmysql_dd_suspend(self);
                  g_mutex_unlock(self->db_thread_mutex);
                  continue;
                }
            }
          else if (!self->db_thread_terminate)
            {
              g_cond_wait(self->db_thread_wakeup_cond, self->db_thread_mutex);
            }

          /* we loop back to check if the thread was requested to terminate */
        }
      g_mutex_unlock(self->db_thread_mutex);

      if (self->db_thread_terminate)
        break;
      
      if (!afmysql_dd_insert_db(self))
        {
          afmysql_dd_disconnect(self);
          afmysql_dd_suspend(self);
        }
    }
    
   while (log_queue_get_length(self->queue) > 0)
    {
      if (!afmysql_dd_insert_db(self))
        {
          goto exit;
        }
    }
    
   if (self->flush_lines_queued > 0)
    {
      /* we can't do anything with the return value here. if commit isn't
       * successful, we get our backlog back, but we have no chance
       * submitting that back to the SQL engine.
       */

      afmysql_dd_commit_txn(self);
    }
 printf("\nend db thread\n");
 exit:
  afmysql_dd_disconnect(self);

  msg_verbose("Database thread finished",
              evt_tag_str("driver", self->super.super.id),
              NULL);
  return NULL;
}

static void
afmysql_dd_start_thread(AFMYSqlDestDriver *self)
{
  self->db_thread = create_worker_thread(afmysql_dd_database_thread, self, TRUE, NULL);
}

static void
afmysql_dd_stop_thread(AFMYSqlDestDriver *self)
{
  g_mutex_lock(self->db_thread_mutex);
  self->db_thread_terminate = TRUE;
  g_cond_signal(self->db_thread_wakeup_cond);
  g_mutex_unlock(self->db_thread_mutex);
  g_thread_join(self->db_thread);
}

static gchar *
afmysql_dd_format_stats_instance(AFMYSqlDestDriver *self)
{
  static gchar persist_name[64];

  g_snprintf(persist_name, sizeof(persist_name),
             "%s,%s,%s,%s,%s",
             self->type, self->host, self->port, self->database, self->table->template);
  return persist_name;
}

static inline gchar *
afmysql_dd_format_persist_name(AFMYSqlDestDriver *self)
{
  static gchar persist_name[256];

  g_snprintf(persist_name, sizeof(persist_name),
             "afmysql_dd(%s,%s,%s,%s,%s)",
             self->type, self->host, self->port, self->database, self->table->template);
  return persist_name;
}


static gboolean
afmysql_dd_init(LogPipe *s)
{
  msg_debug("Begin afmysql_dd_init ",
            NULL);
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *)s;
  GlobalConfig *cfg = log_pipe_get_config(s);

  gint len_cols, len_values;

   if (!log_dest_driver_init_method(s))
   {
     msg_debug("Error in afmysql_dd_init,   if (!log_dest_driver_init_method(s)) returned false",
                NULL);
     return FALSE;
   }

   if (!self->columns || !self->values)
    {
      msg_error("Default columns and values must be specified for database destinations",
                evt_tag_str("database type", self->type),
                NULL);
      return FALSE;
    }
    
  self->queue = log_dest_driver_acquire_queue(&self->super, afmysql_dd_format_persist_name(self));
  log_queue_set_counters(self->queue, self->stored_messages, self->dropped_messages);
  
  if (!self->fields)
    {
      GList *col, *value;
      gint i;

      len_cols = g_list_length(self->columns);
      len_values = g_list_length(self->values);
      if (len_cols != len_values)
        {
          msg_error("The number of columns and values do not match",
                    evt_tag_int("len_columns", len_cols),
                    evt_tag_int("len_values", len_values),
                    NULL);
          /*goto error;*/
	  return FALSE;
        }
      self->fields_len = len_cols;
      self->fields = g_new0(AFMYSqlField, len_cols);
      for (i = 0, col = self->columns, value = self->values; col && value; i++, col = col->next, value = value->next)
        {
          gchar *space;

          space = strchr(col->data, ' ');
          if (space)
            {
              self->fields[i].name = g_strndup(col->data, space - (gchar *) col->data);
              while (*space == ' ')
                space++;
              if (*space != '\0')
                self->fields[i].type = g_strdup(space);
              else
                self->fields[i].type = g_strdup("text");
            }
          else
            {
              self->fields[i].name = g_strdup(col->data);
              self->fields[i].type = g_strdup("text");
            }
          if (!afmysql_dd_check_sql_identifier(self->fields[i].name, FALSE))
            {
              msg_error("Column name is not a proper MYSQL name",
                        evt_tag_str("column", self->fields[i].name),
                        NULL);
              return FALSE;
            }
          if (GPOINTER_TO_UINT(value->data) > 4096)
            {
              self->fields[i].value = log_template_new(cfg, NULL);
              log_template_compile(self->fields[i].value, (gchar *) value->data, NULL);
            }
         else
            {
              switch (GPOINTER_TO_UINT(value->data))
                {
                case AFMYSQL_COLUMN_DEFAULT:
                  self->fields[i].flags |= AFMYSQL_FF_DEFAULT;
                  break;
                default:
                  g_assert_not_reached();
                  break;
                }
            }
	}
    }
   
  self->time_reopen = cfg->time_reopen;
  log_template_options_init(&self->template_options, cfg);
  
  if (self->flush_lines == -1)
    self->flush_lines = cfg->flush_lines;
  if (self->flush_timeout == -1)
    self->flush_timeout = cfg->flush_timeout;
  printf("Debug_val: flush_lines %d\n", self -> flush_lines);
  if ((self->flush_lines > 0 || self->flush_timeout > 0))
    self->flush_lines_queued = 0;
  printf("Debug_val2: flush_lines %d\n", self -> flush_lines);
  afmysql_dd_start_thread(self);
  printf("\nend init : TRUE\n");
  return TRUE;
  
/*error:

  stats_lock();
  stats_unregister_counter(SCS_SQL | SCS_DESTINATION, self->super.super.id, afmysql_dd_format_stats_instance(self), SC_TYPE_STORED, &self->stored_messages);
  stats_unregister_counter(SCS_SQL | SCS_DESTINATION, self->super.super.id, afmysql_dd_format_stats_instance(self), SC_TYPE_DROPPED, &self->dropped_messages);
  stats_unlock();
  fprintf(stderr, "Init failed!\n");
  return FALSE;*/
   
}

static gboolean
afmysql_dd_deinit(LogPipe *s)
{
  msg_debug("dd_deinit started",
            NULL);
  
   AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;

  afmysql_dd_stop_thread(self);
  log_queue_reset_parallel_push(self->queue);

  log_queue_set_counters(self->queue, NULL, NULL);

  stats_lock();
  stats_unregister_counter(SCS_SQL | SCS_DESTINATION, self->super.super.id, afmysql_dd_format_stats_instance(self), SC_TYPE_STORED, &self->stored_messages);
  stats_unregister_counter(SCS_SQL | SCS_DESTINATION, self->super.super.id, afmysql_dd_format_stats_instance(self), SC_TYPE_DROPPED, &self->dropped_messages);
  stats_unlock();

  if (!log_dest_driver_deinit_method(s))
    return FALSE;

   msg_debug("dd_deinit finished succesfully",
            NULL);
  return TRUE;
}

static void
afmysql_dd_queue(LogPipe *s, LogMessage *msg, const LogPathOptions *path_options, gpointer user_data)
{
  msg_debug("Begin dd_queue",
            NULL);
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;
  LogPathOptions local_options;

  if (!path_options->flow_control_requested)
    path_options = log_msg_break_ack(msg, path_options, &local_options);

  log_msg_add_ack(msg, path_options);
  log_queue_push_tail(self->queue, log_msg_ref(msg), path_options);
  log_dest_driver_queue_method(s, msg, path_options, user_data);
  msg_debug("Successfully finished dd_queue",
            NULL);
}

static void
afmysql_dd_free(LogPipe *s)
{
  AFMYSqlDestDriver *self = (AFMYSqlDestDriver *) s;
  gint i;

  log_template_options_destroy(&self->template_options);
  if (self->queue)
    log_queue_unref(self->queue);
  for (i = 0; i < self->fields_len; i++)
    {
      g_free(self->fields[i].name);
      g_free(self->fields[i].type);
      log_template_unref(self->fields[i].value);
    }

  g_free(self->fields);
  g_free(self->host);
  g_free(self->port);
  g_free(self->user);
  g_free(self->password);
  g_free(self->database);
  g_free(self->encoding);
  if (self->null_value)
    g_free(self->null_value);
  string_list_free(self->columns);
  string_list_free(self->indexes);
  string_list_free(self->values);
  log_template_unref(self->table);
  //g_hash_table_destroy(self->validated_tables);
  //g_hash_table_destroy(self->dbd_options);
  //g_hash_table_destroy(self->dbd_options_numeric);
  if (self->session_statements)
    string_list_free(self->session_statements);
  g_mutex_free(self->db_thread_mutex);
  g_cond_free(self->db_thread_wakeup_cond);
  log_dest_driver_free(s);
}

LogDriver *
afmysql_dd_new(void)
{
    msg_debug("Function dd_new started",
            NULL);

  AFMYSqlDestDriver *self = g_new0(AFMYSqlDestDriver, 1);

  log_dest_driver_init_instance(&self->super);
  self->super.super.super.init = afmysql_dd_init;
  self->super.super.super.deinit = afmysql_dd_deinit;
  self->super.super.super.queue = afmysql_dd_queue;
  self->super.super.super.free_fn = afmysql_dd_free;

  //self->type = g_strdup("mysql");
  /*self->host = g_strdup("127.0.0.1");
  self->port = g_strdup("3306");
  self->user = g_strdup("syslog");
  self->password = g_strdup("secret");
  self->database = g_strdup("syslog");*/
  self->encoding = g_strdup("UTF-8");

  self->table = log_template_new(configuration, NULL);
  log_template_compile(self->table, "messages", NULL);
  self->failed_message_counter = 0;

  self->flush_lines = -1;
  self->flush_timeout = -1;
  self->flush_lines_queued = -1;
  self->session_statements = NULL;
  //self->num_retries = MAX_FAILED_ATTEMPTS;

  //self->validated_tables = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
  //self->dbd_options = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
  //self->dbd_options_numeric = g_hash_table_new_full(g_str_hash, g_int_equal, g_free, NULL);

  log_template_options_defaults(&self->template_options);
  init_sequence_number(&self->seq_num);

  self->db_thread_wakeup_cond = g_cond_new();
  self->db_thread_mutex = g_mutex_new();
  msg_debug("Successfully finshed dd_new",
            NULL);
  return &self->super.super;
}

#endif
