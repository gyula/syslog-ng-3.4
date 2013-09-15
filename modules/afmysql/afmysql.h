
#ifndef AFMYSQL_H_INCLUDED
#define AFMYSQL_H_INCLUDED

#include "driver.h"

enum
{
  AFMYSQL_COLUMN_DEFAULT = 1,
};

#if ENABLE_MYSQL

void afmysql_dd_set_host(LogDriver *s, const gchar *host);
void afmysql_dd_set_port(LogDriver *s, gint port);
void afmysql_dd_set_user(LogDriver *s, const gchar *user);
void afmysql_dd_set_password(LogDriver *s, const gchar *password);
void afmysql_dd_set_database(LogDriver *s, const gchar *database);
void afmysql_dd_set_table(LogDriver *s, const gchar *table);
void afmysql_dd_set_columns(LogDriver *s, GList *columns);
void afmysql_dd_set_values(LogDriver *s, GList *values);
void afmysql_dd_set_null_value(LogDriver *s, const gchar *null);
void afmysql_dd_set_indexes(LogDriver *s, GList *indexes);
void afmysql_dd_set_retries(LogDriver *s, gint num_retries);
void afmysql_dd_set_frac_digits(LogDriver *s, gint frac_digits);
void afmysql_dd_set_local_time_zone(LogDriver *s, const gchar *local_time_zone);
void afmysql_dd_set_send_time_zone(LogDriver *s, const gchar *send_time_zone);
void afmysql_dd_set_flush_lines(LogDriver *s, gint flush_lines);
void afmysql_dd_set_flush_timeout(LogDriver *s, gint flush_timeout);
void afmysql_dd_set_session_statements(LogDriver *s, GList *session_statements);
void afmysql_dd_set_flags(LogDriver *s, gint flags);
void afmysql_dd_set_bulk_insert(LogDriver *s, gboolean bulk_insert);
LogDriver *afmysql_dd_new();
void afmysql_dd_set_retries(LogDriver *s, gint num_retries);

#else

#define afmysql_dd_set_host(s, h)
#define afmysql_dd_set_port(s, p)
#define afmysql_dd_set_user(s, u)
#define afmysql_dd_set_password(s, p)
#define afmysql_dd_set_database(s, d)
#define afmysql_dd_set_table(s, t)
#define afmysql_dd_set_columns(s, c)
#define afmysql_dd_set_values(s, v)
#define afmysql_dd_set_null_value(s, v)
#define afmysql_dd_add_dbd_option(s, n, v)
#define afmysql_dd_add_dbd_option_numeric(s, n, v)

#define afmysql_dd_new() 0

#endif

#endif