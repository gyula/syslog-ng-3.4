#include "afsql.h"

#if ENABLE_SQL

#include "logqueue.h"
#include "templates.h"
#include "messages.h"
#include "misc.h"
#include "stats.h"
#include "apphook.h"
#include "timeutils.h"

#include <string.h>

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
 // dbi_conn dbi_ctx;
  GHashTable *validated_tables;
  guint32 failed_message_counter;
} AFMYSqlDestDriver;

//static gboolean dbi_initialized = FALSE;  ?????????? mysql init?

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
      return FALSE;
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
 * afsql_dd_run_query:
 *
 * Run an SQL query on the connected database.
 *
 * NOTE: This function can only be called from the database thread.
 **/
static gboolean
afmysql_dd_run_query(AFMYSqlDestDriver *self, const gchar *query, gboolean silent, mysql_result *result)
{
  /**/
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
afsql_dd_validate_table(AFSqlDestDriver *self, LogMessage *msg)
{
  /*  */
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
 /**/
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
 /**/
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
  /* */
}

static void
afmysql_dd_disconnect(AFMYSqlDestDriver *self)
{
  /**/
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
 /**/
}

static gboolean
afmysql_dd_insert_fail_handler(AFMYSqlDestDriver *self, LogMessage *msg,
                             LogPathOptions *path_options)
{
 /**/
}

static GString *
afmysql_dd_construct_query(AFMYSqlDestDriver *self, GString *table,
                         LogMessage *msg)
{
 /**/
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
  /**/
}

static void
afmysql_dd_message_became_available_in_the_queue(gpointer user_data)
{
  /**/
}

/* assumes that db_thread_mutex is held */
static void
afmysql_dd_wait_for_suspension_wakeup(AFMYSqlDestDriver *self)
{
 /**/
}

/**
 * afsql_dd_database_thread:
 *
 * This is the thread inserting records into the database.
 **/
static gpointer
afmysql_dd_database_thread(gpointer arg)
{
 /**/
}

static void
afmysql_dd_start_thread(AFMYSqlDestDriver *self)
{
  /**/
}

static void
afmysql_dd_stop_thread(AFMYSqlDestDriver *self)
{
  /**/
}

static gchar *
afmysql_dd_format_stats_instance(AFMYSqlDestDriver *self)
{
  /**/
}

static inline gchar *
afmysql_dd_format_persist_name(AFMYSqlDestDriver *self)
{
  /**/
}


static gboolean
afmysql_dd_init(LogPipe *s)
{
   /**/
}

static gboolean
afmysql_dd_deinit(LogPipe *s)
{
  /**/
}

static void
afmysql_dd_queue(LogPipe *s, LogMessage *msg, const LogPathOptions *path_options, gpointer user_data)
{
  /**/
}

static void
afmysql_dd_free(LogPipe *s)
{
  /**/
}

LogDriver *
afsql_dd_new(void)
{
  /**/
}

gint
afsql_dd_lookup_flag(const gchar *flag)
{
  /**/
}

#endif