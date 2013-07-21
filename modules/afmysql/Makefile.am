moduledir = @moduledir@
AM_CPPFLAGS = -I$(top_srcdir)/lib -I../../lib
export top_srcdir

if ENABLE_SQL

module_LTLIBRARIES := libafsql.la
libafsql_la_SOURCES = \
	afmysql.c afmysql.h \
	afmysql-grammar.y afmysql-parser.c afmysql-parser.h afmysql-plugin.c

libafsql_la_CPPFLAGS = $(AM_CPPFLAGS) -DENABLE_SQL=1
libafsql_la_LIBADD = $(MODULE_DEPS_LIBS) $(OPENSSL_LIBS)
libafsql_la_LDFLAGS = $(MODULE_LDFLAGS)

endif

BUILT_SOURCES = afmysql-grammar.y afmysql-grammar.c afmysql-grammar.h
EXTRA_DIST = $(BUILT_SOURCES) afmysql-grammar.ym

include $(top_srcdir)/build/lex-rules.am