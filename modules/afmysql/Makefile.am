moduledir = @moduledir@
AM_CPPFLAGS = -I$(top_srcdir)/lib -I../../lib
export top_srcdir

#if ENABLE_MYSQL

module_LTLIBRARIES := libafmysql.la
libafmysql_la_SOURCES = \
	afmysql.c afmysql.h \
	afmysql-grammar.y afmysql-parser.c afmysql-parser.h afmysql-plugin.c

libafmysql_la_CPPFLAGS = $(AM_CPPFLAGS) -I/usr/include/mysql -DBIG_JOINS=1 -fno-strict-aliasing -g -DENABLE_MYSQL=1
libafmysql_la_LIBADD = $(MODULE_DEPS_LIBS) $(OPENSSL_LIBS) -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -ldl

libafmysql_la_LDFLAGS = $(MODULE_LDFLAGS)

#endif

BUILT_SOURCES = afmysql-grammar.y afmysql-grammar.c afmysql-grammar.h
EXTRA_DIST = $(BUILT_SOURCES) afmysql-grammar.ym

include $(top_srcdir)/build/lex-rules.am
