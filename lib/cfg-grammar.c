/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         main_parse
#define yylex           main_lex
#define yyerror         main_error
#define yylval          main_lval
#define yychar          main_char
#define yydebug         main_debug
#define yynerrs         main_nerrs
#define yylloc          main_lloc

/* Copy the first part of user declarations.  */


/* Line 268 of yacc.c  */
#line 79 "cfg-grammar.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 288 of yacc.c  */
#line 25 "cfg-grammar.y"


/* this block is inserted into cfg-grammar.h, so it is included
   practically all of the syslog-ng code. Please add headers here
   with care. If you need additional headers, please look for a
   massive list of includes further below. */

/* YYSTYPE and YYLTYPE is defined by the lexer */
#include "cfg-lexer.h"
#include "afinter.h"
#include "filter-expr-parser.h"
#include "parser-expr-parser.h"
#include "rewrite-expr-parser.h"

/* uses struct declarations instead of the typedefs to avoid having to
 * include logreader/logwriter/driver.h, which defines the typedefs.  This
 * is to avoid including unnecessary dependencies into grammars that are not
 * themselves reader/writer based */

extern struct _LogSourceOptions *last_source_options;
extern struct _LogReaderOptions *last_reader_options;
extern struct _LogProtoServerOptions *last_proto_server_options;
extern struct _LogWriterOptions *last_writer_options;
extern struct _FilePermOptions *last_file_perm_options;
extern struct _MsgFormatOptions *last_msg_format_options;
extern struct _LogDriver *last_driver;
extern struct _LogParser *last_parser;




/* Line 288 of yacc.c  */
#line 135 "cfg-grammar.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LL_CONTEXT_ROOT = 1,
     LL_CONTEXT_DESTINATION = 2,
     LL_CONTEXT_SOURCE = 3,
     LL_CONTEXT_PARSER = 4,
     LL_CONTEXT_REWRITE = 5,
     LL_CONTEXT_FILTER = 6,
     LL_CONTEXT_LOG = 7,
     LL_CONTEXT_BLOCK_DEF = 8,
     LL_CONTEXT_BLOCK_REF = 9,
     LL_CONTEXT_BLOCK_CONTENT = 10,
     LL_CONTEXT_BLOCK_ARG = 11,
     LL_CONTEXT_PRAGMA = 12,
     LL_CONTEXT_FORMAT = 13,
     LL_CONTEXT_TEMPLATE_FUNC = 14,
     LL_CONTEXT_INNER_DEST = 15,
     LL_CONTEXT_INNER_SRC = 16,
     LL_CONTEXT_CLIENT_PROTO = 17,
     LL_CONTEXT_SERVER_PROTO = 18,
     KW_SOURCE = 10000,
     KW_FILTER = 10001,
     KW_PARSER = 10002,
     KW_DESTINATION = 10003,
     KW_LOG = 10004,
     KW_OPTIONS = 10005,
     KW_INCLUDE = 10006,
     KW_BLOCK = 10007,
     KW_JUNCTION = 10008,
     KW_CHANNEL = 10009,
     KW_INTERNAL = 10010,
     KW_FILE = 10011,
     KW_SQL = 10030,
     KW_TYPE = 10031,
     KW_COLUMNS = 10032,
     KW_INDEXES = 10033,
     KW_VALUES = 10034,
     KW_PASSWORD = 10035,
     KW_DATABASE = 10036,
     KW_USERNAME = 10037,
     KW_TABLE = 10038,
     KW_ENCODING = 10039,
     KW_SESSION_STATEMENTS = 10040,
     KW_DELIMITERS = 10050,
     KW_QUOTES = 10051,
     KW_QUOTE_PAIRS = 10052,
     KW_NULL = 10053,
     KW_SYSLOG = 10060,
     KW_MARK_FREQ = 10071,
     KW_STATS_FREQ = 10072,
     KW_STATS_LEVEL = 10073,
     KW_FLUSH_LINES = 10074,
     KW_SUPPRESS = 10075,
     KW_FLUSH_TIMEOUT = 10076,
     KW_LOG_MSG_SIZE = 10077,
     KW_FILE_TEMPLATE = 10078,
     KW_PROTO_TEMPLATE = 10079,
     KW_MARK_MODE = 10080,
     KW_CHAIN_HOSTNAMES = 10090,
     KW_NORMALIZE_HOSTNAMES = 10091,
     KW_KEEP_HOSTNAME = 10092,
     KW_CHECK_HOSTNAME = 10093,
     KW_BAD_HOSTNAME = 10094,
     KW_KEEP_TIMESTAMP = 10100,
     KW_USE_DNS = 10110,
     KW_USE_FQDN = 10111,
     KW_DNS_CACHE = 10120,
     KW_DNS_CACHE_SIZE = 10121,
     KW_DNS_CACHE_EXPIRE = 10130,
     KW_DNS_CACHE_EXPIRE_FAILED = 10131,
     KW_DNS_CACHE_HOSTS = 10132,
     KW_PERSIST_ONLY = 10140,
     KW_TZ_CONVERT = 10150,
     KW_TS_FORMAT = 10151,
     KW_FRAC_DIGITS = 10152,
     KW_LOG_FIFO_SIZE = 10160,
     KW_LOG_FETCH_LIMIT = 10162,
     KW_LOG_IW_SIZE = 10163,
     KW_LOG_PREFIX = 10164,
     KW_PROGRAM_OVERRIDE = 10165,
     KW_HOST_OVERRIDE = 10166,
     KW_THROTTLE = 10170,
     KW_THREADED = 10171,
     KW_FLAGS = 10190,
     KW_PAD_SIZE = 10200,
     KW_TIME_ZONE = 10201,
     KW_RECV_TIME_ZONE = 10202,
     KW_SEND_TIME_ZONE = 10203,
     KW_LOCAL_TIME_ZONE = 10204,
     KW_FORMAT = 10205,
     KW_TIME_REOPEN = 10210,
     KW_TIME_REAP = 10211,
     KW_TIME_SLEEP = 10212,
     KW_TMPL_ESCAPE = 10220,
     KW_OPTIONAL = 10230,
     KW_CREATE_DIRS = 10240,
     KW_OWNER = 10250,
     KW_GROUP = 10251,
     KW_PERM = 10252,
     KW_DIR_OWNER = 10260,
     KW_DIR_GROUP = 10261,
     KW_DIR_PERM = 10262,
     KW_TEMPLATE = 10270,
     KW_TEMPLATE_ESCAPE = 10271,
     KW_DEFAULT_FACILITY = 10300,
     KW_DEFAULT_LEVEL = 10301,
     KW_PORT = 10323,
     KW_USE_TIME_RECVD = 10340,
     KW_FACILITY = 10350,
     KW_LEVEL = 10351,
     KW_HOST = 10352,
     KW_MATCH = 10353,
     KW_MESSAGE = 10354,
     KW_NETMASK = 10355,
     KW_TAGS = 10356,
     KW_VALUE = 10361,
     KW_REWRITE = 10370,
     KW_SET = 10371,
     KW_SUBST = 10372,
     KW_YES = 10380,
     KW_NO = 10381,
     KW_IFDEF = 10410,
     KW_ENDIF = 10411,
     LL_DOTDOT = 10420,
     LL_IDENTIFIER = 10421,
     LL_NUMBER = 10422,
     LL_FLOAT = 10423,
     LL_STRING = 10424,
     LL_TOKEN = 10425,
     LL_BLOCK = 10426,
     LL_PRAGMA = 10427,
     LL_EOL = 10428,
     LL_ERROR = 10429,
     KW_VALUE_PAIRS = 10500,
     KW_SELECT = 10501,
     KW_EXCLUDE = 10502,
     KW_PAIR = 10503,
     KW_KEY = 10504,
     KW_SCOPE = 10505,
     KW_SHIFT = 10506,
     KW_REKEY = 10507,
     KW_ADD_PREFIX = 10508,
     KW_REPLACE = 10509
   };
#endif
/* Tokens.  */
#define LL_CONTEXT_ROOT 1
#define LL_CONTEXT_DESTINATION 2
#define LL_CONTEXT_SOURCE 3
#define LL_CONTEXT_PARSER 4
#define LL_CONTEXT_REWRITE 5
#define LL_CONTEXT_FILTER 6
#define LL_CONTEXT_LOG 7
#define LL_CONTEXT_BLOCK_DEF 8
#define LL_CONTEXT_BLOCK_REF 9
#define LL_CONTEXT_BLOCK_CONTENT 10
#define LL_CONTEXT_BLOCK_ARG 11
#define LL_CONTEXT_PRAGMA 12
#define LL_CONTEXT_FORMAT 13
#define LL_CONTEXT_TEMPLATE_FUNC 14
#define LL_CONTEXT_INNER_DEST 15
#define LL_CONTEXT_INNER_SRC 16
#define LL_CONTEXT_CLIENT_PROTO 17
#define LL_CONTEXT_SERVER_PROTO 18
#define KW_SOURCE 10000
#define KW_FILTER 10001
#define KW_PARSER 10002
#define KW_DESTINATION 10003
#define KW_LOG 10004
#define KW_OPTIONS 10005
#define KW_INCLUDE 10006
#define KW_BLOCK 10007
#define KW_JUNCTION 10008
#define KW_CHANNEL 10009
#define KW_INTERNAL 10010
#define KW_FILE 10011
#define KW_SQL 10030
#define KW_TYPE 10031
#define KW_COLUMNS 10032
#define KW_INDEXES 10033
#define KW_VALUES 10034
#define KW_PASSWORD 10035
#define KW_DATABASE 10036
#define KW_USERNAME 10037
#define KW_TABLE 10038
#define KW_ENCODING 10039
#define KW_SESSION_STATEMENTS 10040
#define KW_DELIMITERS 10050
#define KW_QUOTES 10051
#define KW_QUOTE_PAIRS 10052
#define KW_NULL 10053
#define KW_SYSLOG 10060
#define KW_MARK_FREQ 10071
#define KW_STATS_FREQ 10072
#define KW_STATS_LEVEL 10073
#define KW_FLUSH_LINES 10074
#define KW_SUPPRESS 10075
#define KW_FLUSH_TIMEOUT 10076
#define KW_LOG_MSG_SIZE 10077
#define KW_FILE_TEMPLATE 10078
#define KW_PROTO_TEMPLATE 10079
#define KW_MARK_MODE 10080
#define KW_CHAIN_HOSTNAMES 10090
#define KW_NORMALIZE_HOSTNAMES 10091
#define KW_KEEP_HOSTNAME 10092
#define KW_CHECK_HOSTNAME 10093
#define KW_BAD_HOSTNAME 10094
#define KW_KEEP_TIMESTAMP 10100
#define KW_USE_DNS 10110
#define KW_USE_FQDN 10111
#define KW_DNS_CACHE 10120
#define KW_DNS_CACHE_SIZE 10121
#define KW_DNS_CACHE_EXPIRE 10130
#define KW_DNS_CACHE_EXPIRE_FAILED 10131
#define KW_DNS_CACHE_HOSTS 10132
#define KW_PERSIST_ONLY 10140
#define KW_TZ_CONVERT 10150
#define KW_TS_FORMAT 10151
#define KW_FRAC_DIGITS 10152
#define KW_LOG_FIFO_SIZE 10160
#define KW_LOG_FETCH_LIMIT 10162
#define KW_LOG_IW_SIZE 10163
#define KW_LOG_PREFIX 10164
#define KW_PROGRAM_OVERRIDE 10165
#define KW_HOST_OVERRIDE 10166
#define KW_THROTTLE 10170
#define KW_THREADED 10171
#define KW_FLAGS 10190
#define KW_PAD_SIZE 10200
#define KW_TIME_ZONE 10201
#define KW_RECV_TIME_ZONE 10202
#define KW_SEND_TIME_ZONE 10203
#define KW_LOCAL_TIME_ZONE 10204
#define KW_FORMAT 10205
#define KW_TIME_REOPEN 10210
#define KW_TIME_REAP 10211
#define KW_TIME_SLEEP 10212
#define KW_TMPL_ESCAPE 10220
#define KW_OPTIONAL 10230
#define KW_CREATE_DIRS 10240
#define KW_OWNER 10250
#define KW_GROUP 10251
#define KW_PERM 10252
#define KW_DIR_OWNER 10260
#define KW_DIR_GROUP 10261
#define KW_DIR_PERM 10262
#define KW_TEMPLATE 10270
#define KW_TEMPLATE_ESCAPE 10271
#define KW_DEFAULT_FACILITY 10300
#define KW_DEFAULT_LEVEL 10301
#define KW_PORT 10323
#define KW_USE_TIME_RECVD 10340
#define KW_FACILITY 10350
#define KW_LEVEL 10351
#define KW_HOST 10352
#define KW_MATCH 10353
#define KW_MESSAGE 10354
#define KW_NETMASK 10355
#define KW_TAGS 10356
#define KW_VALUE 10361
#define KW_REWRITE 10370
#define KW_SET 10371
#define KW_SUBST 10372
#define KW_YES 10380
#define KW_NO 10381
#define KW_IFDEF 10410
#define KW_ENDIF 10411
#define LL_DOTDOT 10420
#define LL_IDENTIFIER 10421
#define LL_NUMBER 10422
#define LL_FLOAT 10423
#define LL_STRING 10424
#define LL_TOKEN 10425
#define LL_BLOCK 10426
#define LL_PRAGMA 10427
#define LL_EOL 10428
#define LL_ERROR 10429
#define KW_VALUE_PAIRS 10500
#define KW_SELECT 10501
#define KW_EXCLUDE 10502
#define KW_PAIR 10503
#define KW_KEY 10504
#define KW_SCOPE 10505
#define KW_SHIFT 10506
#define KW_REKEY 10507
#define KW_ADD_PREFIX 10508
#define KW_REPLACE 10509




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 456 "cfg-grammar.c"
/* Unqualified %code blocks.  */

/* Line 344 of yacc.c  */
#line 69 "cfg-grammar.y"


# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
  do {                                                                  \
    if (YYID (N))                                                       \
      {                                                                 \
        (Current).level = YYRHSLOC(Rhs, 1).level;                       \
        (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;          \
        (Current).first_column = YYRHSLOC (Rhs, 1).first_column;        \
        (Current).last_line    = YYRHSLOC (Rhs, N).last_line;           \
        (Current).last_column  = YYRHSLOC (Rhs, N).last_column;         \
      }                                                                 \
    else                                                                \
      {                                                                 \
        (Current).level = YYRHSLOC(Rhs, 0).level;                       \
        (Current).first_line   = (Current).last_line   =                \
          YYRHSLOC (Rhs, 0).last_line;                                  \
        (Current).first_column = (Current).last_column =                \
          YYRHSLOC (Rhs, 0).last_column;                                \
      }                                                                 \
  } while (YYID (0))

#define CHECK_ERROR(val, token, errorfmt, ...) do {                     \
    if (!(val))                                                         \
      {                                                                 \
        if (errorfmt)                                                   \
          {                                                             \
            gchar __buf[256];                                           \
            g_snprintf(__buf, sizeof(__buf), errorfmt ? errorfmt : "x", ## __VA_ARGS__); \
            yyerror(& (token), lexer, NULL, NULL, __buf);               \
          }                                                             \
        YYERROR;                                                        \
      }                                                                 \
  } while (0)

#define YYMAXDEPTH 20000




/* Line 344 of yacc.c  */
#line 308 "cfg-grammar.y"


#include "cfg-parser.h"
#include "cfg.h"
#include "cfg-tree.h"
#include "templates.h"
#include "logreader.h"
#include "logparser.h"
#include "logrewrite.h"
#include "value-pairs.h"
#include "vptransform.h"
#include "file-perms.h"
#include "filter-expr-parser.h"
#include "rewrite-expr-parser.h"
#include "block-ref-parser.h"
#include "plugin.h"
#include "logwriter.h"
#include "messages.h"

#include "syslog-names.h"

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cfg-grammar.h"

LogDriver *last_driver;
LogParser *last_parser;
LogSourceOptions *last_source_options;
LogProtoServerOptions *last_proto_server_options;
LogReaderOptions *last_reader_options;
LogWriterOptions *last_writer_options;
MsgFormatOptions *last_msg_format_options;
FilePermOptions *last_file_perm_options;
LogTemplate *last_template;
CfgArgs *last_block_args;
ValuePairs *last_value_pairs;
ValuePairsTransformSet *last_vp_transset;




/* Line 344 of yacc.c  */
#line 548 "cfg-grammar.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNRULES -- Number of states.  */
#define YYNSTATES  423

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   10510

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     147,   148,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   149,   144,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   145,     2,   146,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    45,    46,    47,     2,     2,     2,     2,     2,     2,
      48,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      59,    60,    61,    62,    63,     2,     2,     2,     2,     2,
      64,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      65,    66,     2,     2,     2,     2,     2,     2,     2,     2,
      67,    68,     2,     2,     2,     2,     2,     2,     2,     2,
      69,    70,    71,     2,     2,     2,     2,     2,     2,     2,
      72,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      73,    74,    75,     2,     2,     2,     2,     2,     2,     2,
      76,     2,    77,    78,    79,    80,    81,     2,     2,     2,
      82,    83,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      84,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      85,    86,    87,    88,    89,    90,     2,     2,     2,     2,
      91,    92,    93,     2,     2,     2,     2,     2,     2,     2,
      94,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      95,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      96,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      97,    98,    99,     2,     2,     2,     2,     2,     2,     2,
     100,   101,   102,     2,     2,     2,     2,     2,     2,     2,
     103,   104,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     105,   106,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   107,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     108,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     109,   110,   111,   112,   113,   114,   115,     2,     2,     2,
       2,   116,     2,     2,     2,     2,     2,     2,     2,     2,
     117,   118,   119,     2,     2,     2,     2,     2,     2,     2,
     120,   121,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     122,   123,     2,     2,     2,     2,     2,     2,     2,     2,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    36,    42,    48,    54,
      60,    61,    62,    69,    70,    71,    75,    79,    83,    84,
      86,    88,    90,    95,    96,    99,   102,   103,   105,   106,
     107,   108,   109,   110,   114,   118,   122,   123,   125,   127,
     131,   132,   137,   142,   147,   152,   157,   162,   167,   172,
     177,   182,   184,   189,   191,   195,   196,   201,   206,   210,
     216,   217,   220,   221,   226,   227,   234,   238,   239,   244,
     249,   250,   251,   252,   263,   266,   267,   268,   272,   276,
     277,   282,   287,   292,   297,   302,   307,   312,   317,   322,
     327,   332,   337,   342,   347,   352,   357,   362,   367,   372,
     377,   382,   387,   392,   397,   402,   407,   412,   417,   421,
     426,   430,   435,   439,   444,   448,   453,   457,   462,   466,
     471,   476,   481,   486,   491,   496,   501,   506,   511,   516,
     518,   520,   522,   524,   526,   528,   530,   532,   534,   536,
     538,   541,   542,   544,   547,   552,   557,   562,   567,   572,
     577,   582,   587,   592,   597,   602
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     151,     0,    -1,   152,    -1,   153,   144,   152,    -1,    -1,
     154,    -1,   193,    -1,   192,    -1,   197,    -1,   155,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,
      21,   206,   145,   163,   146,    -1,    24,   206,   145,   177,
     146,    -1,    22,   206,   145,   174,   146,    -1,    23,   206,
     145,   175,   146,    -1,   117,   206,   145,   176,   146,    -1,
      -1,    -1,    25,   161,   145,   189,   146,   162,    -1,    -1,
      -1,   164,   166,   165,    -1,   167,   212,   166,    -1,   188,
     212,   166,    -1,    -1,   169,    -1,   168,    -1,   125,    -1,
      31,   147,   170,   148,    -1,    -1,   171,   172,    -1,   173,
     172,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   180,   179,    -1,   181,   212,   180,    -1,   188,   212,
     180,    -1,    -1,   182,    -1,   125,    -1,   184,   212,   183,
      -1,    -1,    21,   147,   206,   148,    -1,    21,   145,   163,
     146,    -1,    22,   147,   206,   148,    -1,    22,   145,   174,
     146,    -1,    23,   147,   206,   148,    -1,    23,   145,   175,
     146,    -1,   117,   147,   206,   148,    -1,   117,   145,   176,
     146,    -1,    24,   147,   206,   148,    -1,    24,   145,   177,
     146,    -1,   185,    -1,    29,   145,   187,   146,    -1,   187,
      -1,   188,   212,   187,    -1,    -1,    25,   145,   189,   146,
      -1,    30,   145,   189,   146,    -1,   183,   186,   190,    -1,
      84,   147,   191,   148,   212,    -1,    -1,   206,   191,    -1,
      -1,    26,   145,   204,   146,    -1,    -1,   103,   206,   194,
     145,   195,   146,    -1,   196,   144,   195,    -1,    -1,   103,
     147,   206,   148,    -1,   104,   147,   207,   148,    -1,    -1,
      -1,    -1,    28,   198,   125,   125,   147,   199,   201,   148,
     200,   130,    -1,   202,   201,    -1,    -1,    -1,   125,   203,
     130,    -1,   205,   144,   204,    -1,    -1,    49,   147,   126,
     148,    -1,    50,   147,   126,   148,    -1,    51,   147,   126,
     148,    -1,    52,   147,   126,   148,    -1,    58,   147,    31,
     148,    -1,    58,   147,   206,   148,    -1,    54,   147,   126,
     148,    -1,    59,   147,   207,   148,    -1,    60,   147,   207,
     148,    -1,    61,   147,   207,   148,    -1,    62,   147,   207,
     148,    -1,    63,   147,   206,   148,    -1,    66,   147,   207,
     148,    -1,    65,   147,   208,   148,    -1,    91,   147,   126,
     148,    -1,    92,   147,   126,   148,    -1,    93,   147,   126,
     148,    -1,    53,   147,   126,   148,    -1,    83,   147,   207,
     148,    -1,    76,   147,   126,   148,    -1,    78,   147,   126,
     148,    -1,    77,   147,   126,   148,    -1,    55,   147,   126,
     148,    -1,    64,   147,   207,   148,    -1,    74,   147,   206,
     148,    -1,    75,   147,   126,   148,    -1,    96,   147,   207,
     148,    -1,    97,   147,   209,   148,    -1,    97,   147,   148,
      -1,    98,   147,   209,   148,    -1,    98,   147,   148,    -1,
      99,   147,   126,   148,    -1,    99,   147,   148,    -1,   100,
     147,   209,   148,    -1,   100,   147,   148,    -1,   101,   147,
     209,   148,    -1,   101,   147,   148,    -1,   102,   147,   126,
     148,    -1,   102,   147,   148,    -1,    67,   147,   207,   148,
      -1,    68,   147,   126,   148,    -1,    69,   147,   126,   148,
      -1,    70,   147,   126,   148,    -1,    71,   147,   206,   148,
      -1,    56,   147,   206,   148,    -1,    57,   147,   206,   148,
      -1,    87,   147,   206,   148,    -1,    88,   147,   206,   148,
      -1,    89,   147,   206,   148,    -1,   125,    -1,   128,    -1,
     120,    -1,   121,    -1,   126,    -1,   207,    -1,    72,    -1,
     206,    -1,   126,    -1,   127,    -1,   211,    -1,   206,   211,
      -1,    -1,   144,    -1,   144,   212,    -1,    78,   147,   126,
     148,    -1,    59,   147,   207,   148,    -1,    60,   147,   207,
     148,    -1,    61,   147,   207,   148,    -1,    66,   147,   207,
     148,    -1,    65,   147,   208,   148,    -1,    67,   147,   207,
     148,    -1,    80,   147,   206,   148,    -1,    81,   147,   206,
     148,    -1,    79,   147,   206,   148,    -1,    64,   147,   207,
     148,    -1,   115,   147,   210,   148,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   418,   418,   422,   423,   427,   431,   432,   433,   437,
     438,   439,   440,   441,   442,   446,   453,   462,   470,   478,
     486,   488,   485,   499,   501,   499,   508,   509,   510,   514,
     515,   519,   538,   542,   542,   550,   551,   555,   560,   571,
     581,   590,   592,   590,   601,   602,   603,   607,   611,   630,
     631,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   649,   661,   666,   667,   671,   672,   676,   680,
     681,   685,   686,   692,   697,   696,   708,   709,   713,   719,
     725,   727,   728,   724,   748,   749,   754,   753,   765,   766,
     770,   771,   772,   773,   774,   775,   780,   781,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   792,   793,
     794,   795,   796,   797,   798,   799,   800,   801,   802,   803,
     804,   805,   806,   807,   808,   809,   810,   811,   812,   813,
     814,   815,   816,   818,   819,   820,   821,   822,   823,   829,
     830,   834,   835,   836,   840,   841,   845,   846,   847,   851,
     855,   856,   860,   861,   912,   913,   914,   915,   916,   917,
     918,   919,   920,   921,   922,   923
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LL_CONTEXT_ROOT",
  "LL_CONTEXT_DESTINATION", "LL_CONTEXT_SOURCE", "LL_CONTEXT_PARSER",
  "LL_CONTEXT_REWRITE", "LL_CONTEXT_FILTER", "LL_CONTEXT_LOG",
  "LL_CONTEXT_BLOCK_DEF", "LL_CONTEXT_BLOCK_REF",
  "LL_CONTEXT_BLOCK_CONTENT", "LL_CONTEXT_BLOCK_ARG", "LL_CONTEXT_PRAGMA",
  "LL_CONTEXT_FORMAT", "LL_CONTEXT_TEMPLATE_FUNC", "LL_CONTEXT_INNER_DEST",
  "LL_CONTEXT_INNER_SRC", "LL_CONTEXT_CLIENT_PROTO",
  "LL_CONTEXT_SERVER_PROTO", "KW_SOURCE", "KW_FILTER", "KW_PARSER",
  "KW_DESTINATION", "KW_LOG", "KW_OPTIONS", "KW_INCLUDE", "KW_BLOCK",
  "KW_JUNCTION", "KW_CHANNEL", "KW_INTERNAL", "KW_FILE", "KW_SQL",
  "KW_TYPE", "KW_COLUMNS", "KW_INDEXES", "KW_VALUES", "KW_PASSWORD",
  "KW_DATABASE", "KW_USERNAME", "KW_TABLE", "KW_ENCODING",
  "KW_SESSION_STATEMENTS", "KW_DELIMITERS", "KW_QUOTES", "KW_QUOTE_PAIRS",
  "KW_NULL", "KW_SYSLOG", "KW_MARK_FREQ", "KW_STATS_FREQ",
  "KW_STATS_LEVEL", "KW_FLUSH_LINES", "KW_SUPPRESS", "KW_FLUSH_TIMEOUT",
  "KW_LOG_MSG_SIZE", "KW_FILE_TEMPLATE", "KW_PROTO_TEMPLATE",
  "KW_MARK_MODE", "KW_CHAIN_HOSTNAMES", "KW_NORMALIZE_HOSTNAMES",
  "KW_KEEP_HOSTNAME", "KW_CHECK_HOSTNAME", "KW_BAD_HOSTNAME",
  "KW_KEEP_TIMESTAMP", "KW_USE_DNS", "KW_USE_FQDN", "KW_DNS_CACHE",
  "KW_DNS_CACHE_SIZE", "KW_DNS_CACHE_EXPIRE", "KW_DNS_CACHE_EXPIRE_FAILED",
  "KW_DNS_CACHE_HOSTS", "KW_PERSIST_ONLY", "KW_TZ_CONVERT", "KW_TS_FORMAT",
  "KW_FRAC_DIGITS", "KW_LOG_FIFO_SIZE", "KW_LOG_FETCH_LIMIT",
  "KW_LOG_IW_SIZE", "KW_LOG_PREFIX", "KW_PROGRAM_OVERRIDE",
  "KW_HOST_OVERRIDE", "KW_THROTTLE", "KW_THREADED", "KW_FLAGS",
  "KW_PAD_SIZE", "KW_TIME_ZONE", "KW_RECV_TIME_ZONE", "KW_SEND_TIME_ZONE",
  "KW_LOCAL_TIME_ZONE", "KW_FORMAT", "KW_TIME_REOPEN", "KW_TIME_REAP",
  "KW_TIME_SLEEP", "KW_TMPL_ESCAPE", "KW_OPTIONAL", "KW_CREATE_DIRS",
  "KW_OWNER", "KW_GROUP", "KW_PERM", "KW_DIR_OWNER", "KW_DIR_GROUP",
  "KW_DIR_PERM", "KW_TEMPLATE", "KW_TEMPLATE_ESCAPE",
  "KW_DEFAULT_FACILITY", "KW_DEFAULT_LEVEL", "KW_PORT",
  "KW_USE_TIME_RECVD", "KW_FACILITY", "KW_LEVEL", "KW_HOST", "KW_MATCH",
  "KW_MESSAGE", "KW_NETMASK", "KW_TAGS", "KW_VALUE", "KW_REWRITE",
  "KW_SET", "KW_SUBST", "KW_YES", "KW_NO", "KW_IFDEF", "KW_ENDIF",
  "LL_DOTDOT", "LL_IDENTIFIER", "LL_NUMBER", "LL_FLOAT", "LL_STRING",
  "LL_TOKEN", "LL_BLOCK", "LL_PRAGMA", "LL_EOL", "LL_ERROR",
  "KW_VALUE_PAIRS", "KW_SELECT", "KW_EXCLUDE", "KW_PAIR", "KW_KEY",
  "KW_SCOPE", "KW_SHIFT", "KW_REKEY", "KW_ADD_PREFIX", "KW_REPLACE", "';'",
  "'{'", "'}'", "'('", "')'", "':'", "$accept", "start", "stmts", "stmt",
  "expr_stmt", "source_stmt", "dest_stmt", "filter_stmt", "parser_stmt",
  "rewrite_stmt", "log_stmt", "$@1", "$@2", "source_content", "$@3", "$@4",
  "source_items", "source_item", "source_plugin", "source_afinter",
  "source_afinter_params", "$@5", "source_afinter_options",
  "source_afinter_option", "filter_content", "parser_content",
  "rewrite_content", "dest_content", "$@6", "$@7", "dest_items",
  "dest_item", "dest_plugin", "log_items", "log_item", "log_junction",
  "log_last_junction", "log_forks", "log_fork", "log_content", "log_flags",
  "log_flags_items", "options_stmt", "template_stmt", "$@8",
  "template_items", "template_item", "block_stmt", "$@9", "$@10", "$@11",
  "block_args", "block_arg", "$@12", "options_items", "options_item",
  "string", "yesno", "dnsmode", "string_or_number", "string_list",
  "string_list_build", "semicolons", "source_option", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256, 10510,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18, 10000, 10001, 10002, 10003, 10004, 10005, 10006, 10007, 10008,
   10009, 10010, 10011, 10030, 10031, 10032, 10033, 10034, 10035, 10036,
   10037, 10038, 10039, 10040, 10050, 10051, 10052, 10053, 10060, 10071,
   10072, 10073, 10074, 10075, 10076, 10077, 10078, 10079, 10080, 10090,
   10091, 10092, 10093, 10094, 10100, 10110, 10111, 10120, 10121, 10130,
   10131, 10132, 10140, 10150, 10151, 10152, 10160, 10162, 10163, 10164,
   10165, 10166, 10170, 10171, 10190, 10200, 10201, 10202, 10203, 10204,
   10205, 10210, 10211, 10212, 10220, 10230, 10240, 10250, 10251, 10252,
   10260, 10261, 10262, 10270, 10271, 10300, 10301, 10323, 10340, 10350,
   10351, 10352, 10353, 10354, 10355, 10356, 10361, 10370, 10371, 10372,
   10380, 10381, 10410, 10411, 10420, 10421, 10422, 10423, 10424, 10425,
   10426, 10427, 10428, 10429, 10500, 10501, 10502, 10503, 10504, 10505,
   10506, 10507, 10508, 10509,    59,   123,   125,    40,    41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   150,   151,   152,   152,   153,   153,   153,   153,   154,
     154,   154,   154,   154,   154,   155,   156,   157,   158,   159,
     161,   162,   160,   164,   165,   163,   166,   166,   166,   167,
     167,   168,   169,   171,   170,   172,   172,   173,   174,   175,
     176,   178,   179,   177,   180,   180,   180,   181,   182,   183,
     183,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   185,   186,   187,   187,   188,   188,   189,   190,
     190,   191,   191,   192,   194,   193,   195,   195,   196,   196,
     198,   199,   200,   197,   201,   201,   203,   202,   204,   204,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   206,
     206,   207,   207,   207,   208,   208,   209,   209,   209,   210,
     211,   211,   212,   212,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     5,     5,     5,
       0,     0,     6,     0,     0,     3,     3,     3,     0,     1,
       1,     1,     4,     0,     2,     2,     0,     1,     0,     0,
       0,     0,     0,     3,     3,     3,     0,     1,     1,     3,
       0,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     1,     4,     1,     3,     0,     4,     4,     3,     5,
       0,     2,     0,     4,     0,     6,     3,     0,     4,     4,
       0,     0,     0,    10,     2,     0,     0,     3,     3,     0,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     4,
       3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,    20,     0,    80,     0,     0,
       0,     2,     0,     5,     9,    10,    11,    12,    13,    14,
       7,     6,     8,   139,   140,     0,     0,     0,     0,     0,
      89,     0,    74,     0,     1,     4,    23,    38,    39,    41,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     3,     0,
      28,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,    65,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    89,     0,
      77,     0,    15,     0,     0,     0,    31,    24,     0,    30,
      29,     0,    17,    18,    16,    48,    42,     0,    47,     0,
      23,     0,    38,     0,    39,     0,    41,     0,    65,    40,
       0,    70,    63,     0,   152,    50,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   142,
     143,     0,     0,     0,     0,     0,     0,   145,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
     148,   118,   146,     0,   120,     0,     0,   122,   124,     0,
     126,     0,     0,   128,    88,    81,     0,     0,     0,     0,
      19,    50,    50,    33,    25,    28,    28,    43,    46,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    65,   153,    49,    22,    90,    91,    92,
      93,   107,    96,   112,   134,   135,    94,    95,    97,    98,
      99,   100,   101,   113,   103,   102,   129,   130,   131,   132,
     133,   114,   115,   109,   111,   110,   108,   136,   137,   138,
     104,   105,   106,   116,   117,   119,   121,   123,   125,   127,
      85,     0,     0,    75,    77,     0,     0,     0,    36,    26,
      27,    44,    45,    52,    51,    54,    53,    56,    55,    60,
      59,    62,    58,    57,    72,    64,    86,     0,    85,     0,
       0,    76,    66,    67,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    36,    37,
       0,    72,     0,    82,    84,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,    35,
       0,    71,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,     0,   149,    69,    83,
     155,   156,   157,   164,   159,   158,   160,   154,   163,   161,
     162,   150,   165
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    29,   276,    89,    90,   254,   157,   158,   159,   160,
     327,   328,   367,   368,    91,    92,   151,    93,    94,   257,
     166,   167,   168,   101,   102,   103,   181,   182,   161,   104,
     272,   370,    20,    21,    86,   248,   249,    22,    31,   320,
     393,   347,   348,   372,    83,    84,   232,   208,   209,   233,
     406,   407,   185,   369
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -174
static const yytype_int16 yypact[] =
{
      21,   -89,   -89,   -89,   -89,  -174,  -139,  -174,   -89,   -89,
      37,  -174,   -96,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,   -67,   -56,   -36,   -29,   -17,
     144,     6,  -174,   -13,  -174,    21,  -174,  -174,  -174,  -174,
      29,   -11,   -10,    -8,    -7,    -6,    -4,    -3,     1,     2,
       3,     4,     5,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    22,    24,    26,
      28,    33,    34,    35,    36,    38,    39,    40,    41,    42,
      43,    44,    70,    78,    79,    59,    23,  -174,  -174,    80,
      -2,    82,    83,    84,     0,   -42,   -39,   -30,   -26,    89,
     -25,    77,    81,  -174,    92,    27,   113,   122,   123,   124,
     125,   126,   -89,   -89,   -27,   -88,   -88,   -88,   -88,   -89,
     -88,   -41,   -88,   -88,   127,   128,   129,   -89,   -89,   130,
     131,   132,   133,   -88,   -89,   -89,   -89,   134,   135,   136,
     -88,   -62,   -58,   -91,   -44,   -34,   -49,  -174,   144,   116,
     -32,   118,  -174,   120,   121,   137,  -174,  -174,    81,  -174,
    -174,    81,  -174,  -174,  -174,  -174,  -174,    81,  -174,    81,
    -174,   -89,  -174,   -89,  -174,   -89,  -174,   -89,    77,  -174,
     -89,    58,  -174,    81,    81,    29,  -174,   119,   138,   139,
     140,   141,   142,   143,   145,   146,   147,   148,  -174,  -174,
    -174,   149,   150,   151,   152,   153,   154,  -174,  -174,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   173,   174,   175,  -174,
    -174,  -174,  -174,   176,  -174,   177,   178,  -174,  -174,   179,
    -174,   180,   181,  -174,  -174,  -174,   183,   184,   186,   189,
    -174,    29,    29,  -174,  -174,    -2,    -2,  -174,     0,     0,
     188,   187,   190,   191,   192,   193,   194,   196,   199,   200,
     201,   195,  -174,    77,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
     212,   -89,   -88,  -174,   -32,   202,   204,   203,    -5,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,   -89,  -174,  -174,   205,   212,   206,
     207,  -174,  -174,  -174,  -174,   209,   210,   211,   213,   214,
     215,   216,   217,   218,   219,   220,   221,  -174,    -5,  -174,
     223,   -89,   222,  -174,  -174,  -174,  -174,   -88,   -88,   -88,
     -88,   -41,   -88,   -88,   233,   -89,   -89,   -89,   -89,  -174,
      81,  -174,  -174,   239,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   234,   235,   -89,   240,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,   110,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,   -23,  -174,  -174,  -168,  -174,  -174,  -174,
    -174,  -174,  -100,  -174,    97,    96,    99,   103,  -174,  -174,
    -163,  -174,  -174,    90,  -174,  -174,  -174,  -173,   -81,  -122,
    -174,   -90,  -174,  -174,  -174,    57,  -174,  -174,  -174,  -174,
    -174,   -68,  -174,  -174,   241,  -174,    -1,  -106,   -99,  -123,
    -174,  -120,  -143,  -174
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      25,    26,    27,    28,   196,   268,    30,    32,    33,   201,
     202,   203,   204,   169,   206,   255,   210,   211,   256,   235,
     183,   239,   241,   153,   258,   153,   259,   221,   154,   155,
     154,   207,   198,   199,   228,   236,    23,    34,   200,    24,
     273,   274,     1,     2,     3,     4,     5,     6,    35,     7,
      95,    96,    97,    98,   355,   356,   357,   237,    99,   358,
     359,   360,   361,    23,   229,   230,    24,    23,   229,   230,
      24,   246,   247,   362,   363,   364,   365,   242,    36,   198,
     199,    23,   229,   230,    24,   200,   231,   329,   330,    37,
     234,    23,   229,   230,    24,   331,   332,   183,    23,   243,
     345,    24,   153,   170,   238,   171,   172,   154,   173,    38,
     366,   194,   195,   197,   240,   174,    39,   175,   205,   176,
     179,   177,   180,   156,     8,   165,   215,   216,    40,   325,
     326,    85,    87,   222,   223,   224,   105,   106,     9,   107,
     108,   109,   271,   110,   111,    88,   100,   260,   112,   113,
     114,   115,   116,   187,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   150,   131,
     261,   132,   263,   133,   265,   134,   267,   169,   169,   270,
     135,   136,   137,   138,   149,   139,   140,   141,   142,   143,
     144,   145,   183,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   350,   146,    64,    65,
      66,    67,    68,   148,   147,   184,   152,    69,   162,   163,
     164,    70,    71,    72,   178,    73,    74,    75,   186,   188,
      76,    77,    78,    79,    80,    81,    82,   408,   189,   190,
     191,   192,   193,   212,   213,   214,   217,   218,   219,   220,
     225,   226,   227,   245,   250,   251,   252,   277,   389,   262,
     264,   394,   395,   396,   397,   275,   399,   400,   269,   266,
     374,   391,   398,     0,   253,   421,   278,   279,   280,   281,
     282,   283,     0,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     349,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     321,   322,   323,   324,   333,   334,   335,   346,   337,   336,
     339,   338,   344,   371,   340,   341,   342,     0,   352,   343,
     353,   354,   392,   373,   375,   376,   377,   378,   379,   401,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   409,
     371,   390,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   351,   419,   420,   402,   403,   404,   405,   422,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   405
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-174))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,     2,     3,     4,    31,   178,   145,     8,     9,   115,
     116,   117,   118,    94,   120,   158,   122,   123,   161,   142,
     101,   144,   145,    25,   167,    25,   169,   133,    30,    31,
      30,    72,   120,   121,   140,   126,   125,     0,   126,   128,
     183,   184,    21,    22,    23,    24,    25,    26,   144,    28,
      21,    22,    23,    24,    59,    60,    61,   148,    29,    64,
      65,    66,    67,   125,   126,   127,   128,   125,   126,   127,
     128,   103,   104,    78,    79,    80,    81,   126,   145,   120,
     121,   125,   126,   127,   128,   126,   148,   255,   256,   145,
     148,   125,   126,   127,   128,   258,   259,   178,   125,   148,
     273,   128,    25,   145,   148,   147,   145,    30,   147,   145,
     115,   112,   113,   114,   148,   145,   145,   147,   119,   145,
     145,   147,   147,   125,   103,   125,   127,   128,   145,   251,
     252,   125,   145,   134,   135,   136,   147,   147,   117,   147,
     147,   147,    84,   147,   147,    35,   117,   170,   147,   147,
     147,   147,   147,   126,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   145,   147,
     171,   147,   173,   147,   175,   147,   177,   258,   259,   180,
     147,   147,   147,   147,   125,   147,   147,   147,   147,   147,
     147,   147,   273,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   322,   147,    74,    75,
      76,    77,    78,   144,   146,   144,   146,    83,   146,   146,
     146,    87,    88,    89,   145,    91,    92,    93,   146,   126,
      96,    97,    98,    99,   100,   101,   102,   390,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   147,   146,   145,   145,   148,   368,   172,
     174,   377,   378,   379,   380,   185,   382,   383,   179,   176,
     348,   371,   381,    -1,   147,   405,   148,   148,   148,   148,
     148,   148,    -1,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     321,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     147,   147,   146,   144,   146,   148,   146,   125,   146,   148,
     146,   148,   147,   344,   148,   146,   146,    -1,   146,   148,
     146,   148,   130,   148,   148,   148,   147,   147,   147,   126,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   130,
     371,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   324,   148,   148,   385,   386,   387,   388,   148,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   405
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    22,    23,    24,    25,    26,    28,   103,   117,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     192,   193,   197,   125,   128,   206,   206,   206,   206,   161,
     145,   198,   206,   206,     0,   144,   145,   145,   145,   145,
     145,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    74,    75,    76,    77,    78,    83,
      87,    88,    89,    91,    92,    93,    96,    97,    98,    99,
     100,   101,   102,   204,   205,   125,   194,   145,   152,   163,
     164,   174,   175,   177,   178,    21,    22,    23,    24,    29,
     117,   183,   184,   185,   189,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   146,   144,   125,
     145,   176,   146,    25,    30,    31,   125,   166,   167,   168,
     169,   188,   146,   146,   146,   125,   180,   181,   182,   188,
     145,   147,   145,   147,   145,   147,   145,   147,   145,   145,
     147,   186,   187,   188,   144,   212,   146,   126,   126,   126,
     126,   126,   126,   126,   206,   206,    31,   206,   120,   121,
     126,   207,   207,   207,   207,   206,   207,    72,   207,   208,
     207,   207,   126,   126,   126,   206,   206,   126,   126,   126,
     126,   207,   206,   206,   206,   126,   126,   126,   207,   126,
     127,   148,   206,   209,   148,   209,   126,   148,   148,   209,
     148,   209,   126,   148,   204,   147,   103,   104,   195,   196,
     146,   145,   145,   147,   165,   212,   212,   179,   212,   212,
     163,   206,   174,   206,   175,   206,   177,   206,   187,   176,
     206,    84,   190,   212,   212,   183,   162,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     199,   147,   147,   146,   144,   189,   189,   170,   171,   166,
     166,   180,   180,   146,   148,   146,   148,   146,   148,   146,
     148,   146,   146,   148,   147,   187,   125,   201,   202,   206,
     207,   195,   146,   146,   148,    59,    60,    61,    64,    65,
      66,    67,    78,    79,    80,    81,   115,   172,   173,   213,
     191,   206,   203,   148,   201,   148,   148,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   172,
     148,   191,   130,   200,   207,   207,   207,   207,   208,   207,
     207,   126,   206,   206,   206,   206,   210,   211,   212,   130,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   211,   148
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (&yylloc, lexer, dummy, arg, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, lexer)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, lexer, dummy, arg); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, CfgLexer *lexer, gpointer *dummy, gpointer arg)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, lexer, dummy, arg)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    CfgLexer *lexer;
    gpointer *dummy;
    gpointer arg;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (lexer);
  YYUSE (dummy);
  YYUSE (arg);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, CfgLexer *lexer, gpointer *dummy, gpointer arg)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, lexer, dummy, arg)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    CfgLexer *lexer;
    gpointer *dummy;
    gpointer arg;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, lexer, dummy, arg);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, CfgLexer *lexer, gpointer *dummy, gpointer arg)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, lexer, dummy, arg)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    CfgLexer *lexer;
    gpointer *dummy;
    gpointer arg;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , lexer, dummy, arg);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, lexer, dummy, arg); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, CfgLexer *lexer, gpointer *dummy, gpointer arg)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, lexer, dummy, arg)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    CfgLexer *lexer;
    gpointer *dummy;
    gpointer arg;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (lexer);
  YYUSE (dummy);
  YYUSE (arg);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (CfgLexer *lexer, gpointer *dummy, gpointer arg);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (CfgLexer *lexer, gpointer *dummy, gpointer arg)
#else
int
yyparse (lexer, dummy, arg)
    CfgLexer *lexer;
    gpointer *dummy;
    gpointer arg;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

/* Line 1806 of yacc.c  */
#line 428 "cfg-grammar.y"
    {
            CHECK_ERROR(cfg_tree_add_object(&configuration->tree, (yyvsp[(1) - (1)].ptr)) || cfg_allow_config_dups(configuration), (yylsp[(1) - (1)]), "duplicate %s definition", log_expr_node_get_content_name(((LogExprNode *) (yyvsp[(1) - (1)].ptr))->content));
          }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 447 "cfg-grammar.y"
    {
            (yyval.ptr) = log_expr_node_new_source((yyvsp[(2) - (5)].cptr), (yyvsp[(4) - (5)].ptr), &(yylsp[(1) - (5)]));
            free((yyvsp[(2) - (5)].cptr));
          }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 454 "cfg-grammar.y"
    {
            (yyval.ptr) = log_expr_node_new_destination((yyvsp[(2) - (5)].cptr), (yyvsp[(4) - (5)].ptr), &(yylsp[(1) - (5)]));
            free((yyvsp[(2) - (5)].cptr));
          }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 463 "cfg-grammar.y"
    {
            (yyval.ptr) = log_expr_node_new_filter((yyvsp[(2) - (5)].cptr), (yyvsp[(4) - (5)].ptr), &(yylsp[(1) - (5)]));
            free((yyvsp[(2) - (5)].cptr));
          }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 471 "cfg-grammar.y"
    {
            (yyval.ptr) = log_expr_node_new_parser((yyvsp[(2) - (5)].cptr), (yyvsp[(4) - (5)].ptr), &(yylsp[(1) - (5)]));
            free((yyvsp[(2) - (5)].cptr));
          }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 479 "cfg-grammar.y"
    {
            (yyval.ptr) = log_expr_node_new_rewrite((yyvsp[(2) - (5)].cptr), (yyvsp[(4) - (5)].ptr), &(yylsp[(1) - (5)]));
            free((yyvsp[(2) - (5)].cptr));
          }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 486 "cfg-grammar.y"
    { cfg_lexer_push_context(lexer, LL_CONTEXT_LOG, NULL, "log"); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 488 "cfg-grammar.y"
    { cfg_lexer_pop_context(lexer); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 489 "cfg-grammar.y"
    {
            (yyval.ptr) = (yyvsp[(4) - (6)].ptr);
          }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 499 "cfg-grammar.y"
    { cfg_lexer_push_context(lexer, LL_CONTEXT_SOURCE, NULL, "source"); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 501 "cfg-grammar.y"
    { cfg_lexer_pop_context(lexer); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 502 "cfg-grammar.y"
    {
            (yyval.ptr) = log_expr_node_new_junction((yyvsp[(2) - (3)].ptr), &(yyloc));
          }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 508 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_append_tail(log_expr_node_new_pipe((yyvsp[(1) - (3)].ptr), &(yylsp[(1) - (3)])), (yyvsp[(3) - (3)].ptr)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 509 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_append_tail((yyvsp[(1) - (3)].ptr),  (yyvsp[(3) - (3)].ptr)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 510 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 514 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 515 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 520 "cfg-grammar.y"
    {
            Plugin *p;
            gint context = LL_CONTEXT_SOURCE;

            p = plugin_find(configuration, context, (yyvsp[(1) - (1)].cptr));
            CHECK_ERROR(p, (yylsp[(1) - (1)]), "%s plugin %s not found", cfg_lexer_lookup_context_name_by_type(context), (yyvsp[(1) - (1)].cptr));

            last_driver = (LogDriver *) plugin_parse_config(p, configuration, &(yylsp[(1) - (1)]), NULL);
            free((yyvsp[(1) - (1)].cptr));
            if (!last_driver)
              {
                YYERROR;
              }
            (yyval.ptr) = last_driver;
          }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 538 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 542 "cfg-grammar.y"
    {
            last_driver = afinter_sd_new();
            last_source_options = &((AFInterSourceDriver *) last_driver)->source_options;
          }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 546 "cfg-grammar.y"
    { (yyval.ptr) = last_driver; }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 560 "cfg-grammar.y"
    {
            FilterExprNode *last_filter_expr = NULL;

	    CHECK_ERROR(cfg_parser_parse(&filter_expr_parser, lexer, (gpointer *) &last_filter_expr, NULL), (yyloc), NULL);

            (yyval.ptr) = log_expr_node_new_pipe(log_filter_pipe_new(last_filter_expr), &(yyloc));
	  }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 571 "cfg-grammar.y"
    {
            LogExprNode *last_parser_expr = NULL;

            CHECK_ERROR(cfg_parser_parse(&parser_expr_parser, lexer, (gpointer *) &last_parser_expr, NULL), (yyloc), NULL);
            (yyval.ptr) = last_parser_expr;
          }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 581 "cfg-grammar.y"
    {
            LogExprNode *last_rewrite_expr = NULL;

            CHECK_ERROR(cfg_parser_parse(&rewrite_expr_parser, lexer, (gpointer *) &last_rewrite_expr, NULL), (yyloc), NULL);
            (yyval.ptr) = last_rewrite_expr;
          }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 590 "cfg-grammar.y"
    { cfg_lexer_push_context(lexer, LL_CONTEXT_DESTINATION, NULL, "destination"); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 592 "cfg-grammar.y"
    { cfg_lexer_pop_context(lexer); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 593 "cfg-grammar.y"
    {
             (yyval.ptr) = log_expr_node_new_junction((yyvsp[(2) - (3)].ptr), &(yyloc));
           }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 601 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_append_tail(log_expr_node_new_pipe((yyvsp[(1) - (3)].ptr), &(yylsp[(1) - (3)])), (yyvsp[(3) - (3)].ptr)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 602 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_append_tail((yyvsp[(1) - (3)].ptr),  (yyvsp[(3) - (3)].ptr)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 603 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 607 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 612 "cfg-grammar.y"
    {
            Plugin *p;
            gint context = LL_CONTEXT_DESTINATION;

            p = plugin_find(configuration, context, (yyvsp[(1) - (1)].cptr));
            CHECK_ERROR(p, (yylsp[(1) - (1)]), "%s plugin %s not found", cfg_lexer_lookup_context_name_by_type(context), (yyvsp[(1) - (1)].cptr));

            last_driver = (LogDriver *) plugin_parse_config(p, configuration, &(yylsp[(1) - (1)]), NULL);
            free((yyvsp[(1) - (1)].cptr));
            if (!last_driver)
              {
                YYERROR;
              }
            (yyval.ptr) = last_driver;
          }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 630 "cfg-grammar.y"
    { log_expr_node_append_tail((yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr)); (yyval.ptr) = (yyvsp[(1) - (3)].ptr); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 631 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 635 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_source_reference((yyvsp[(3) - (4)].cptr), &(yyloc)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 636 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_source(NULL, (yyvsp[(3) - (4)].ptr), &(yyloc)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 637 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_filter_reference((yyvsp[(3) - (4)].cptr), &(yyloc)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 638 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_filter(NULL, (yyvsp[(3) - (4)].ptr), &(yyloc)); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 639 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_parser_reference((yyvsp[(3) - (4)].cptr), &(yyloc)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 640 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_parser(NULL, (yyvsp[(3) - (4)].ptr), &(yyloc)); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 641 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_rewrite_reference((yyvsp[(3) - (4)].cptr), &(yyloc)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 642 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_rewrite(NULL, (yyvsp[(3) - (4)].ptr), &(yyloc)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 643 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_destination_reference((yyvsp[(3) - (4)].cptr), &(yyloc)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 644 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_destination(NULL, (yyvsp[(3) - (4)].ptr), &(yyloc)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 645 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 649 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_junction((yyvsp[(3) - (4)].ptr), &(yyloc)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 661 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr) ? log_expr_node_new_junction((yyvsp[(1) - (1)].ptr), &(yylsp[(1) - (1)])) :  NULL; }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 666 "cfg-grammar.y"
    { log_expr_node_append_tail((yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr)); (yyval.ptr) = (yyvsp[(1) - (3)].ptr); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 667 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 671 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 672 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(3) - (4)].ptr); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 676 "cfg-grammar.y"
    { (yyval.ptr) = log_expr_node_new_log(log_expr_node_append_tail((yyvsp[(1) - (3)].ptr), (yyvsp[(2) - (3)].ptr)), (yyvsp[(3) - (3)].num), &(yyloc)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 680 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[(3) - (5)].num); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 681 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 685 "cfg-grammar.y"
    { (yyval.num) = log_expr_node_lookup_flag((yyvsp[(1) - (2)].cptr)) | (yyvsp[(2) - (2)].num); free((yyvsp[(1) - (2)].cptr)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 686 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 697 "cfg-grammar.y"
    {
	    last_template = log_template_new(configuration, (yyvsp[(2) - (2)].cptr));
	    free((yyvsp[(2) - (2)].cptr));
	  }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 702 "cfg-grammar.y"
    {
            CHECK_ERROR(cfg_tree_add_template(&configuration->tree, last_template) || cfg_allow_config_dups(configuration), (yylsp[(2) - (6)]), "duplicate template");
          }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 713 "cfg-grammar.y"
    {
                                                  GError *error = NULL;

                                                  CHECK_ERROR(log_template_compile(last_template, (yyvsp[(3) - (4)].cptr), &error), (yylsp[(3) - (4)]), "Error compiling template (%s)", error->message);
                                                  free((yyvsp[(3) - (4)].cptr));
                                                }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 719 "cfg-grammar.y"
    { log_template_set_escape(last_template, (yyvsp[(3) - (4)].num)); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 725 "cfg-grammar.y"
    { cfg_lexer_push_context(lexer, LL_CONTEXT_BLOCK_DEF, block_def_keywords, "block definition"); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 727 "cfg-grammar.y"
    { last_block_args = cfg_args_new(); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 728 "cfg-grammar.y"
    { cfg_lexer_push_context(lexer, LL_CONTEXT_BLOCK_CONTENT, NULL, "block content"); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 730 "cfg-grammar.y"
    {
            CfgBlock *block;

            /* block content */
            cfg_lexer_pop_context(lexer);
            /* block definition */
            cfg_lexer_pop_context(lexer);

            block = cfg_block_new((yyvsp[(10) - (10)].cptr), last_block_args);
            CHECK_ERROR(cfg_lexer_register_block_generator(lexer, cfg_lexer_lookup_context_type_by_name((yyvsp[(3) - (10)].cptr)), (yyvsp[(4) - (10)].cptr), cfg_block_generate, block, (GDestroyNotify) cfg_block_free) || cfg_allow_config_dups(configuration), (yylsp[(4) - (10)]), "duplicate block definition");
            free((yyvsp[(3) - (10)].cptr));
            free((yyvsp[(4) - (10)].cptr));
            free((yyvsp[(10) - (10)].cptr));
            last_block_args = NULL;
          }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 754 "cfg-grammar.y"
    {
            cfg_lexer_push_context(lexer, LL_CONTEXT_BLOCK_ARG, NULL, "block argument");
          }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 758 "cfg-grammar.y"
    {
            cfg_lexer_pop_context(lexer);
            cfg_args_set(last_block_args, (yyvsp[(1) - (3)].cptr), (yyvsp[(3) - (3)].cptr)); free((yyvsp[(1) - (3)].cptr)); free((yyvsp[(3) - (3)].cptr));
          }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 765 "cfg-grammar.y"
    { (yyval.ptr) = (yyvsp[(1) - (3)].ptr); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 766 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 770 "cfg-grammar.y"
    { configuration->mark_freq = (yyvsp[(3) - (4)].num); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 771 "cfg-grammar.y"
    { configuration->stats_freq = (yyvsp[(3) - (4)].num); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 772 "cfg-grammar.y"
    { configuration->stats_level = (yyvsp[(3) - (4)].num); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 773 "cfg-grammar.y"
    { configuration->flush_lines = (yyvsp[(3) - (4)].num); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 774 "cfg-grammar.y"
    { cfg_set_mark_mode(configuration, "internal"); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 776 "cfg-grammar.y"
    {
            CHECK_ERROR(cfg_lookup_mark_mode((yyvsp[(3) - (4)].cptr)) > 0 && cfg_lookup_mark_mode((yyvsp[(3) - (4)].cptr)) != MM_GLOBAL, (yylsp[(3) - (4)]), "illegal global mark-mode");
            free((yyvsp[(3) - (4)].cptr));
          }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 780 "cfg-grammar.y"
    { configuration->flush_timeout = (yyvsp[(3) - (4)].num); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 781 "cfg-grammar.y"
    { configuration->chain_hostnames = (yyvsp[(3) - (4)].num); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 782 "cfg-grammar.y"
    { configuration->normalize_hostnames = (yyvsp[(3) - (4)].num); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 783 "cfg-grammar.y"
    { configuration->keep_hostname = (yyvsp[(3) - (4)].num); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 784 "cfg-grammar.y"
    { configuration->check_hostname = (yyvsp[(3) - (4)].num); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 785 "cfg-grammar.y"
    { cfg_bad_hostname_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 786 "cfg-grammar.y"
    { configuration->use_fqdn = (yyvsp[(3) - (4)].num); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 787 "cfg-grammar.y"
    { configuration->use_dns = (yyvsp[(3) - (4)].num); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 788 "cfg-grammar.y"
    { configuration->time_reopen = (yyvsp[(3) - (4)].num); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 789 "cfg-grammar.y"
    { configuration->time_reap = (yyvsp[(3) - (4)].num); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 790 "cfg-grammar.y"
    {}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 791 "cfg-grammar.y"
    { configuration->suppress = (yyvsp[(3) - (4)].num); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 792 "cfg-grammar.y"
    { configuration->threaded = (yyvsp[(3) - (4)].num); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 793 "cfg-grammar.y"
    { configuration->log_fifo_size = (yyvsp[(3) - (4)].num); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 794 "cfg-grammar.y"
    { msg_error("Using a global log-iw-size() option was removed, please use a per-source log-iw-size()", NULL); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 795 "cfg-grammar.y"
    { msg_error("Using a global log-fetch-limit() option was removed, please use a per-source log-fetch-limit()", NULL); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 796 "cfg-grammar.y"
    { configuration->log_msg_size = (yyvsp[(3) - (4)].num); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 797 "cfg-grammar.y"
    { configuration->keep_timestamp = (yyvsp[(3) - (4)].num); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 798 "cfg-grammar.y"
    { configuration->template_options.ts_format = cfg_ts_format_value((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 799 "cfg-grammar.y"
    { configuration->template_options.frac_digits = (yyvsp[(3) - (4)].num); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 800 "cfg-grammar.y"
    { configuration->create_dirs = (yyvsp[(3) - (4)].num); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 801 "cfg-grammar.y"
    { cfg_file_owner_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 802 "cfg-grammar.y"
    { cfg_file_owner_set(configuration, "-2"); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 803 "cfg-grammar.y"
    { cfg_file_group_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 804 "cfg-grammar.y"
    { cfg_file_group_set(configuration, "-2"); }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 805 "cfg-grammar.y"
    { cfg_file_perm_set(configuration, (yyvsp[(3) - (4)].num)); }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 806 "cfg-grammar.y"
    { cfg_file_perm_set(configuration, -2); }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 807 "cfg-grammar.y"
    { cfg_dir_owner_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 808 "cfg-grammar.y"
    { cfg_dir_owner_set(configuration, "-2"); }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 809 "cfg-grammar.y"
    { cfg_dir_group_set(configuration, (yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 810 "cfg-grammar.y"
    { cfg_dir_group_set(configuration, "-2"); }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 811 "cfg-grammar.y"
    { cfg_dir_perm_set(configuration, (yyvsp[(3) - (4)].num)); }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 812 "cfg-grammar.y"
    { cfg_dir_perm_set(configuration, -2); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 813 "cfg-grammar.y"
    { configuration->use_dns_cache = (yyvsp[(3) - (4)].num); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 814 "cfg-grammar.y"
    { configuration->dns_cache_size = (yyvsp[(3) - (4)].num); }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 815 "cfg-grammar.y"
    { configuration->dns_cache_expire = (yyvsp[(3) - (4)].num); }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 817 "cfg-grammar.y"
    { configuration->dns_cache_expire_failed = (yyvsp[(3) - (4)].num); }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 818 "cfg-grammar.y"
    { configuration->dns_cache_hosts = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 819 "cfg-grammar.y"
    { configuration->file_template_name = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 820 "cfg-grammar.y"
    { configuration->proto_template_name = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 821 "cfg-grammar.y"
    { configuration->recv_time_zone = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 822 "cfg-grammar.y"
    { configuration->template_options.time_zone[LTZ_SEND] = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 823 "cfg-grammar.y"
    { configuration->template_options.time_zone[LTZ_LOCAL] = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 834 "cfg-grammar.y"
    { (yyval.num) = 1; }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 835 "cfg-grammar.y"
    { (yyval.num) = 0; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 836 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 840 "cfg-grammar.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 841 "cfg-grammar.y"
    { (yyval.num) = 2; }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 845 "cfg-grammar.y"
    { (yyval.cptr) = (yyvsp[(1) - (1)].cptr); }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 846 "cfg-grammar.y"
    { (yyval.cptr) = strdup(lexer->token_text->str); }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 847 "cfg-grammar.y"
    { (yyval.cptr) = strdup(lexer->token_text->str); }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 851 "cfg-grammar.y"
    { (yyval.ptr) = g_list_reverse((yyvsp[(1) - (1)].ptr)); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 855 "cfg-grammar.y"
    { (yyval.ptr) = g_list_append((yyvsp[(2) - (2)].ptr), g_strdup((yyvsp[(1) - (2)].cptr))); free((yyvsp[(1) - (2)].cptr)); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 856 "cfg-grammar.y"
    { (yyval.ptr) = NULL; }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 912 "cfg-grammar.y"
    { last_source_options->init_window_size = (yyvsp[(3) - (4)].num); }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 913 "cfg-grammar.y"
    { last_source_options->chain_hostnames = (yyvsp[(3) - (4)].num); }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 914 "cfg-grammar.y"
    { last_source_options->normalize_hostnames = (yyvsp[(3) - (4)].num); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 915 "cfg-grammar.y"
    { last_source_options->keep_hostname = (yyvsp[(3) - (4)].num); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 916 "cfg-grammar.y"
    { last_source_options->use_fqdn = (yyvsp[(3) - (4)].num); }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 917 "cfg-grammar.y"
    { last_source_options->use_dns = (yyvsp[(3) - (4)].num); }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 918 "cfg-grammar.y"
    { last_source_options->use_dns_cache = (yyvsp[(3) - (4)].num); }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 919 "cfg-grammar.y"
    { last_source_options->program_override = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 920 "cfg-grammar.y"
    { last_source_options->host_override = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 921 "cfg-grammar.y"
    { gchar *p = strrchr((yyvsp[(3) - (4)].cptr), ':'); if (p) *p = 0; last_source_options->program_override = g_strdup((yyvsp[(3) - (4)].cptr)); free((yyvsp[(3) - (4)].cptr)); }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 922 "cfg-grammar.y"
    { last_source_options->keep_timestamp = (yyvsp[(3) - (4)].num); }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 923 "cfg-grammar.y"
    { log_source_options_set_tags(last_source_options, (yyvsp[(3) - (4)].ptr)); }
    break;



/* Line 1806 of yacc.c  */
#line 4335 "cfg-grammar.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, lexer, dummy, arg, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, lexer, dummy, arg, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, lexer, dummy, arg);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, lexer, dummy, arg);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, lexer, dummy, arg, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, lexer, dummy, arg);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, lexer, dummy, arg);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1107 "cfg-grammar.y"



