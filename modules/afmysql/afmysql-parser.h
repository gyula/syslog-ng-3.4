#ifndef AFSOCKET_PARSER_H_INCLUDED
#define AFSOCKET_PARSER_H_INCLUDED

#include "cfg-parser.h"
#include "cfg-lexer.h"
#include "driver.h"

extern CfgParser afmysql_parser;

CFG_PARSER_DECLARE_LEXER_BINDING(afmysql_, LogDriver **)

#endif