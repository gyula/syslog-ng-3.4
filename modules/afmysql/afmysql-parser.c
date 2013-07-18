#include "afmysql.h"
#include "cfg-parser.h"
#include "afmysql-grammar.h"

extern int afmysql_debug;

int afmysql_parse(CfgLexer *lexer, LogDriver **instance, gpointer arg);

static CfgLexerKeyword afmysql_keywords[] = {
  { "sql",                KW_SQL },
  { "username",           KW_USERNAME },
  { "password",           KW_PASSWORD },
  { "database",           KW_DATABASE },
  { "table",              KW_TABLE },

  { "columns",            KW_COLUMNS },
  { "indexes",            KW_INDEXES },
  { "values",             KW_VALUES },
  { "log_fifo_size",      KW_LOG_FIFO_SIZE },
  { "frac_digits",        KW_FRAC_DIGITS },
  { "session_statements", KW_SESSION_STATEMENTS, 0x0302 },
  { "host",               KW_HOST },
  { "port",               KW_PORT },
  { "type",               KW_TYPE },
  { "default",            KW_DEFAULT },

  { "time_zone",          KW_TIME_ZONE },
  { "local_time_zone",    KW_LOCAL_TIME_ZONE },
  { "null",               KW_NULL },
  { "retry_sql_inserts",  KW_RETRIES, 0x0303 },
  { "retries",            KW_RETRIES, 0x0303 },
  { "flush_lines",        KW_FLUSH_LINES },
  { "flush_timeout",      KW_FLUSH_TIMEOUT },
  { "flags",              KW_FLAGS },

  { "dbd_option",         KW_DBD_OPTION },
  { NULL }
};

CfgParser afmysql_parser =
{
#if ENABLE_DEBUG
  .debug_flag = &afmysql_debug,
#endif
  .name = "afmysql",
  .keywords = afmysql_keywords,
  .parse = (gint (*)(CfgLexer *, gpointer *, gpointer)) afmysql_parse,
  .cleanup = (void (*)(gpointer)) log_pipe_unref,
};

CFG_PARSER_IMPLEMENT_LEXER_BINDING(afmysql_, LogDriver **)