#include "cfg-lexer.h"
#include "cfg-lex.h"
#include "cfg-grammar.h"
#include "messages.h"

#include <string.h>
#include <sys/stat.h>

#define KWS_NORMAL        0
#define KWS_OBSOLETE      1

static CfgLexerKeyword global_keywords[] = {
        /* statements */
        { "source",             KW_SOURCE },
        { "filter",             KW_FILTER },
        { "parser",             KW_PARSER },
        { "rewrite",            KW_REWRITE },
        { "destination",        KW_DESTINATION },
        { "log",                KW_LOG },
        { "options",            KW_OPTIONS },
        { "include",            KW_INCLUDE },

        /* source or destination items */
        { "file",               KW_FILE },
        { "fifo",               KW_PIPE },
        { "pipe",               KW_PIPE },
        { "internal",           KW_INTERNAL },
        { "usertty",            KW_USERTTY },
        { "door",               KW_DOOR },
#if ENABLE_SUN_STREAMS
        { "sun_stream",         KW_SUN_STREAMS },
        { "sun_streams",        KW_SUN_STREAMS },
#endif
        { "program",            KW_PROGRAM },
/* BEGIN MARK: sql */
#if ENABLE_SQL
        { "sql",                KW_SQL },
        { "username",           KW_USERNAME },
        { "password",           KW_PASSWORD },
        { "database",           KW_DATABASE },
        { "encoding",           KW_ENCODING },
        { "table",              KW_TABLE },

        { "columns",            KW_COLUMNS },
        { "indexes",            KW_INDEXES },
        { "values",             KW_VALUES },
#endif
/* END MARK */
        { "columns",            KW_COLUMNS },
        { "delimiters",         KW_DELIMITERS },
        { "quotes",             KW_QUOTES },
        { "quote_pairs",        KW_QUOTE_PAIRS },
        { "null",               KW_NULL },
        { "csv_parser",         KW_CSV_PARSER },
        { "db_parser",          KW_DB_PARSER },

        /* option items */
        { "flags",              KW_FLAGS },
        { "pad_size",           KW_PAD_SIZE },
        { "mark_freq",          KW_MARK_FREQ },
        { "mark",               KW_MARK_FREQ, KWS_OBSOLETE, "mark_freq" },
        { "stats_freq",         KW_STATS_FREQ },
        { "stats_level",        KW_STATS_LEVEL },
        { "stats",              KW_STATS_FREQ, KWS_OBSOLETE, "stats_freq" },
        { "flush_lines",        KW_FLUSH_LINES },
        { "flush_timeout",      KW_FLUSH_TIMEOUT },
        { "suppress",           KW_SUPPRESS },
        { "sync_freq",          KW_FLUSH_LINES, KWS_OBSOLETE, "flush_lines" },
        { "sync",               KW_FLUSH_LINES, KWS_OBSOLETE, "flush_lines" },
        { "fsync",              KW_FSYNC },
        { "long_hostnames",     KW_CHAIN_HOSTNAMES },
        { "chain_hostnames",    KW_CHAIN_HOSTNAMES },
        { "normalize_hostnames",KW_NORMALIZE_HOSTNAMES },
        { "keep_hostname",      KW_KEEP_HOSTNAME },
        { "check_hostname",     KW_CHECK_HOSTNAME },
        { "bad_hostname",       KW_BAD_HOSTNAME },
        { "keep_timestamp",     KW_KEEP_TIMESTAMP },
        { "encoding",           KW_ENCODING },
        { "ts_format",          KW_TS_FORMAT },
        { "frac_digits",        KW_FRAC_DIGITS },
        { "time_zone",          KW_TIME_ZONE },
        { "recv_time_zone",     KW_RECV_TIME_ZONE },
        { "send_time_zone",     KW_SEND_TIME_ZONE },
        { "local_time_zone",    KW_LOCAL_TIME_ZONE },
        { "use_time_recvd",     KW_USE_TIME_RECVD, KWS_OBSOLETE, "Use R_ or S_ prefixed macros in templates" },
        { "use_fqdn",           KW_USE_FQDN },
        { "use_dns",            KW_USE_DNS },
        { "gc_threshold",       KW_GC_BUSY_THRESHOLD },
        { "gc_busy_threshold",  KW_GC_BUSY_THRESHOLD },
        { "gc_idle_threshold",  KW_GC_IDLE_THRESHOLD },
        { "time_reopen",        KW_TIME_REOPEN },
        { "time_reap",          KW_TIME_REAP },
        { "time_sleep",         KW_TIME_SLEEP },
        { "follow_freq",        KW_FOLLOW_FREQ,  },
        { "remove_if_older",    KW_OVERWRITE_IF_OLDER, KWS_OBSOLETE, "overwrite_if_older" },
        { "overwrite_if_older", KW_OVERWRITE_IF_OLDER },
        { "file_template",      KW_FILE_TEMPLATE },
        { "proto_template",     KW_PROTO_TEMPLATE },
        { "default_level",      KW_DEFAULT_LEVEL },
        { "default_priority",   KW_DEFAULT_LEVEL },
        { "default_facility",   KW_DEFAULT_FACILITY },
#if ENABLE_TIMESTAMPING
        { "timestamp_url",      KW_TIMESTAMP_URL },
        { "timestamp_freq",     KW_TIMESTAMP_FREQ },
#endif
        { "set",                KW_SET },
        { "subst",              KW_SUBST },
        { "value",              KW_VALUE },

        { "log_fifo_size",      KW_LOG_FIFO_SIZE },
        { "log_disk_fifo_size", KW_LOG_DISK_FIFO_SIZE },
        { "log_fetch_limit",    KW_LOG_FETCH_LIMIT },
        { "log_iw_size",        KW_LOG_IW_SIZE },
        { "log_msg_size",       KW_LOG_MSG_SIZE },
        { "log_prefix",         KW_LOG_PREFIX, KWS_OBSOLETE, "program_override" },
        { "program_override",   KW_PROGRAM_OVERRIDE },
        { "host_override",      KW_HOST_OVERRIDE },
        { "throttle",           KW_THROTTLE },

        { "create_dirs",        KW_CREATE_DIRS },
        { "optional",           KW_OPTIONAL },
        { "localip",            KW_LOCALIP },
        { "ip",                 KW_IP },
        { "localport",          KW_LOCALPORT },
        { "port",               KW_PORT },
        { "destport",           KW_DESTPORT },
        { "ip_ttl",             KW_IP_TTL },
        { "ip_tos",             KW_IP_TOS },
        { "so_broadcast",       KW_SO_BROADCAST },
        { "so_rcvbuf",          KW_SO_RCVBUF },
        { "so_sndbuf",          KW_SO_SNDBUF },
        { "so_keepalive",       KW_SO_KEEPALIVE },
        { "tcp_keep_alive",     KW_SO_KEEPALIVE, KWS_OBSOLETE, "so_keepalive" },
        { "spoof_source",       KW_SPOOF_SOURCE },
        { "transport",          KW_TRANSPORT },

        { "owner",              KW_OWNER },
        { "group",              KW_GROUP },
        { "perm",               KW_PERM },
        { "dir_owner",          KW_DIR_OWNER },
        { "dir_group",          KW_DIR_GROUP },
        { "dir_perm",           KW_DIR_PERM },
        { "template",           KW_TEMPLATE },
        { "template_escape",    KW_TEMPLATE_ESCAPE },
        { "keep_alive",         KW_KEEP_ALIVE },
        { "max_connections",    KW_MAX_CONNECTIONS },
        { "mac",                KW_MAC },
        { "authentication",     KW_AUTH },
        { "encrypt",            KW_ENCRYPT },
        { "compress",           KW_COMPRESS },
        { "persist_only",       KW_PERSIST_ONLY },
        { "dns_cache_hosts",    KW_DNS_CACHE_HOSTS },
        { "dns_cache",          KW_DNS_CACHE },
        { "dns_cache_size",     KW_DNS_CACHE_SIZE },
        { "dns_cache_expire",   KW_DNS_CACHE_EXPIRE },
        { "dns_cache_expire_failed", KW_DNS_CACHE_EXPIRE_FAILED },

#if ENABLE_SSL /* BEGIN MARK: tls */
        /* ssl */
        { "tls",                KW_TLS },
        { "peer_verify",        KW_PEER_VERIFY },
        { "key_file",           KW_KEY_FILE },
        { "cert_file",          KW_CERT_FILE },
        { "ca_dir",             KW_CA_DIR },
        { "crl_dir",            KW_CRL_DIR },
        { "trusted_keys",       KW_TRUSTED_KEYS },
        { "trusted_dn",         KW_TRUSTED_DN },
#endif /* END MARK */

        /* filter items */
        { "or",                 KW_OR },
        { "and",                KW_AND },
        { "not",                KW_NOT },
        { "level",              KW_LEVEL },
        { "priority",           KW_LEVEL },
        { "facility",           KW_FACILITY },
        { "program",            KW_PROGRAM },
        { "host",               KW_HOST },
        { "message",            KW_MESSAGE },
        { "match",              KW_MATCH },
        { "netmask",            KW_NETMASK },
        { "type",               KW_TYPE },
        { "tags",               KW_TAGS },

        /* on/off switches */
        { "yes",                KW_YES },
        { "on",                 KW_YES },
        { "no",                 KW_NO },
        { "off",                KW_NO },
        { NULL, 0 }
};

void
cfg_lexer_append_string(CfgLexer *self, int length, char *s)
{
  g_string_append_len(self->pattern_buffer, s, length);
}

void
cfg_lexer_append_char(CfgLexer *self, char c)
{
  g_string_append_c(self->pattern_buffer, c);
}

void
cfg_lexer_set_current_keywords(CfgLexer *self, CfgLexerKeyword *keywords)
{
  self->current_keywords = keywords;
}

static char *
cfg_lexer_get_keyword_string_in_table(CfgLexer *self, int kw, CfgLexerKeyword *keywords)
{
  gint i;
  YYLTYPE *lloc = cfg_lexer_get_yylloc(self);

  for (i = 0; keywords[i].kw_name; i++)
    {
      if (keywords[i].kw_token == kw)
        {
          msg_warning("WARNING: Your configuration uses a newly introduced reserved word as identifier, please use a different name",
                      evt_tag_str("keyword", keywords[i].kw_name),
                      evt_tag_str("filename", lloc->filename),
                      evt_tag_printf("line", "%d:%d", lloc->first_line, lloc->first_column),
                      NULL);
          return strdup(keywords[i].kw_name);
        }
    }
  g_assert_not_reached();
}

char *
cfg_lexer_get_keyword_string(CfgLexer *self, int kw)
{
  char *res;

  res = cfg_lexer_get_keyword_string_in_table(self, kw, self->current_keywords);
  if (!res)
    res = cfg_lexer_get_keyword_string_in_table(self, kw, global_keywords);
  return res;
}

int
cfg_lexer_lookup_keyword_in_table(CfgLexer *self, YYSTYPE *yylval, char *token, CfgLexerKeyword *keywords)
{
  int i, j;

  for (i = 0; keywords[i].kw_name; i++)
    {
      for (j = 0; token[j] && keywords[i].kw_name[j]; j++)
        {
          if (token[j] == '-' || token[j] == '_')
            {
              if (keywords[i].kw_name[j] != '_')
                break;
            }
          else if (token[j] != keywords[i].kw_name[j])
            break;
        }
      if (token[j] == 0 && keywords[i].kw_name[j] == 0)
        {

          switch (keywords[i].kw_status)
            {
            case KWS_OBSOLETE:
              msg_warning("Your configuration file uses an obsoleted keyword, please update your configuration",
                          evt_tag_str("keyword", keywords[i].kw_name),
                          evt_tag_str("change", keywords[i].kw_explain),
                          NULL);
              break;
            default:
              break;
            }
          keywords[i].kw_status = KWS_NORMAL;
          yylval->type = LL_TOKEN;
          yylval->token = keywords[i].kw_token;
          return keywords[i].kw_token;
        }
    }
  yylval->cptr = strdup(token);
  return LL_IDENTIFIER;
}

int
cfg_lexer_lookup_keyword(CfgLexer *self, YYSTYPE *yylval, char *token)
{
  gint res = LL_IDENTIFIER;

  if (self->current_keywords)
    res = cfg_lexer_lookup_keyword_in_table(self, yylval, token, self->current_keywords);
  if (res == LL_IDENTIFIER)
    res = cfg_lexer_lookup_keyword_in_table(self, yylval, token, global_keywords);
  return res;
}

YYLTYPE *
cfg_lexer_get_yylloc(CfgLexer *self)
{
  CfgIncludeLevel *level = &self->include_stack[self->include_depth];

  return &level->lloc;
}

gboolean
cfg_lexer_start_next_include(CfgLexer *self, gboolean first_on_this_level)
{
  CfgIncludeLevel *level = &self->include_stack[self->include_depth];
  gchar *filename;

  if (self->include_depth == 0)
    {
      return FALSE;
    }

  if (!first_on_this_level)
    {
      msg_debug("Finishing include file",
                evt_tag_str("filename", level->lloc.filename),
                evt_tag_int("depth", self->include_depth),
                NULL);
    }

  if (!level->files)
    {
      /* we finished with an include statement that included a series of
       * files (e.g.  directory include). */

      if (!first_on_this_level)
        {
          _cfg_lexer__delete_buffer(level->yybuf, self->state);
          level->yybuf = NULL;
        }
      g_free(level->lloc.filename);
      level->lloc.filename = NULL;

      fclose(level->include_file);
      level->include_file = NULL;

      self->include_depth--;
      _cfg_lexer__switch_to_buffer(self->include_stack[self->include_depth].yybuf, self->state);

      return TRUE;
    }

  filename = (gchar *) level->files->data;
  level->files = g_slist_delete_link(level->files, level->files);

  level->include_file = fopen(filename, "r");
  if (!level->include_file)
    {
      msg_error("Error opening include file",
                evt_tag_str("filename", filename),
                evt_tag_int("depth", self->include_depth),
                NULL);
      g_free(filename);
      return FALSE;
    }
  msg_debug("Starting to read include file",
            evt_tag_str("filename", filename),
            evt_tag_int("depth", self->include_depth),
            NULL);
  if (level->lloc.filename)
    {
      g_free(level->lloc.filename);
      level->lloc.filename = NULL;
    }
  if (level->include_file)
    {
      fclose(level->include_file);
      level->include_file = NULL;
    }

  if (!first_on_this_level)
    _cfg_lexer__delete_buffer(level->yybuf, self->state);

  level->yybuf = _cfg_lexer__create_buffer(level->include_file, YY_BUF_SIZE, self->state);
  level->lloc.filename = filename;
  level->lloc.first_line = 1;

  _cfg_lexer__switch_to_buffer(level->yybuf, self->state);
  return TRUE;
}

gboolean
cfg_lexer_process_include(CfgLexer *self, const gchar *filename)
{
  struct stat st;
  gchar buf[1024];
  CfgIncludeLevel *level;

  if (self->include_depth >= MAX_INCLUDE_DEPTH - 1)
    {
      msg_error("Include file depth is too deep, increase MAX_INCLUDE_DEPTH and recompile",
                evt_tag_str("filename", filename),
                evt_tag_int("depth", self->include_depth),
                NULL);
      return FALSE;
    }

  if (filename[0] != '/')
    {
      g_snprintf(buf, sizeof(buf), "%s/%s", PATH_SYSCONFDIR, filename);
      filename = buf;
    }

  if (stat(filename, &st) < 0)
    {
      msg_error("Include file/directory not found",
                evt_tag_str("filename", filename),
                evt_tag_errno("error", errno),
                NULL);
      return FALSE;
    }
  self->include_depth++;
  level = &self->include_stack[self->include_depth];
  if (S_ISDIR(st.st_mode))
    {
      GDir *dir;
      GError *error = NULL;
      const gchar *entry;

      dir = g_dir_open(filename, 0, &error);
      if (!dir)
        {
          msg_error("Error opening directory for reading",
                evt_tag_str("filename", filename),
                evt_tag_str("error", error->message),
                NULL);
          goto drop_level;
        }
      while ((entry = g_dir_read_name(dir)))
        {
          const gchar *p;

          for (p = entry; *p; p++)
            {
              if (!((*p >= 'a' && *p <= 'z') ||
                   (*p >= 'A' && *p <= 'Z') ||
                   (*p >= '0' && *p <= '9') ||
                   (*p == '_') || (*p == '-') || (*p == '.')))
                {
                  msg_debug("Skipping include file, does not match pattern [\\-_a-zA-Z0-9]+",
                            evt_tag_str("filename", entry),
                            NULL);
                  p = NULL;
                  break;
                }
            }
          if (p)
            {
              gchar *full_filename = g_build_filename(filename, entry, NULL);
              if (stat(full_filename, &st) < 0 || S_ISDIR(st.st_mode))
                {
                  msg_debug("Skipping include file as it is a directory",
                            evt_tag_str("filename", entry),
                            NULL);
                  g_free(full_filename);
                  continue;
                }
              level->files = g_slist_insert_sorted(level->files, full_filename, (GCompareFunc) strcmp);
              msg_debug("Adding include file",
                        evt_tag_str("filename", entry),
                        NULL);
            }
        }
      g_dir_close(dir);
      if (!level->files)
        {
          /* no include files in the specified directory */
          msg_debug("No files in this include directory",
                    evt_tag_str("dir", filename),
                    NULL);
          self->include_depth--;
          return TRUE;
        }
    }
  else
    {
      g_assert(level->files == NULL);
      level->files = g_slist_prepend(level->files, g_strdup(filename));
    }
  return cfg_lexer_start_next_include(self, TRUE);
 drop_level:
  g_slist_foreach(level->files, (GFunc) g_free, NULL);
  g_slist_free(level->files);
  level->files = NULL;
  return FALSE;
}

void
cfg_lexer_add_token_block(CfgLexer *self, CfgTokenBlock *block)
{
  self->token_blocks = g_list_append(self->token_blocks, block);
}

int
cfg_lexer_lex(CfgLexer *self, YYSTYPE *yylval, YYLTYPE *yylloc)
{
  CfgTokenBlock *block;
  YYSTYPE *token;
  gint tok;

  while (self->token_blocks)
    {
      block = self->token_blocks->data;
      token = cfg_token_block_get_token(block);

      if (token)
        {
          *yylval = *token;
          *yylloc = self->include_stack[self->include_depth].lloc;
          return token->type == LL_TOKEN ? token->token : token->type;
        }
      else
        {
          self->token_blocks = g_list_remove_link(self->token_blocks, self->token_blocks);
          cfg_token_block_free(block);
        }
    }
  tok = _cfg_lexer_lex(yylval, yylloc, self->state);
  yylval->type = tok;
  return tok;
}

CfgLexer *
cfg_lexer_new(FILE *file, const gchar *filename, gint init_line_num)
{
  CfgLexer *self;
  CfgIncludeLevel *level;

  self = g_new0(CfgLexer, 1);

  _cfg_lexer_lex_init_extra(self, &self->state);
  _cfg_lexer_restart(file, self->state);
  level = &self->include_stack[0];
  level->lloc.filename = g_strdup(filename);
  level->lloc.first_line = level->lloc.last_line = init_line_num;
  level->lloc.first_column = level->lloc.last_column = 1;
  level->yybuf = _cfg_lexer__create_buffer(file, YY_BUF_SIZE, self->state);
  _cfg_lexer__switch_to_buffer(level->yybuf, self->state);
  self->current_keywords = NULL;
  self->pattern_buffer = g_string_sized_new(32);

  return self;
}

void
cfg_lexer_free(CfgLexer *self)
{
  gint i;

  for (i = 0; i <= self->include_depth; i++)
    {
      CfgIncludeLevel *level = &self->include_stack[i];

      if (level->lloc.filename)
        {
          g_free(level->lloc.filename);
          level->lloc.filename = NULL;
        }

      g_slist_foreach(level->files, (GFunc) g_free, NULL);
      g_slist_free(level->files);
      level->files = NULL;
      if (level->yybuf)
        {
          _cfg_lexer__delete_buffer(level->yybuf, self->state);
          level->yybuf = NULL;
        }
    }
  _cfg_lexer_lex_destroy(self->state);
  self->include_depth = 0;
  g_string_free(self->pattern_buffer, TRUE);
  g_free(self);
}


/* token blocks */

void
cfg_token_block_add_token(CfgTokenBlock *self, YYSTYPE *token)
{
  g_assert(self->pos == 0);
  g_array_append_val(self->tokens, *token);
}

YYSTYPE *
cfg_token_block_get_token(CfgTokenBlock *self)
{
  if (self->pos < self->tokens->len)
    {
      YYSTYPE *result;

      result = &g_array_index(self->tokens, YYSTYPE, self->pos);
      self->pos++;
      return result;
    }
  return NULL;
}

CfgTokenBlock *
cfg_token_block_new()
{
  CfgTokenBlock *self = g_new0(CfgTokenBlock, 1);

  self->tokens = g_array_new(FALSE, TRUE, sizeof(YYSTYPE));
  return self;
}

void
cfg_token_block_free(CfgTokenBlock *self)
{
  gint i;

  for (i = 0; i < self->tokens->len; i++)
    {
      YYSTYPE *token = &g_array_index(self->tokens, YYSTYPE, i);

      if (token->type == LL_STRING || token->type == LL_IDENTIFIER)
        g_free(token->cptr);

    }
  g_array_free(self->tokens, TRUE);
  g_free(self);
}