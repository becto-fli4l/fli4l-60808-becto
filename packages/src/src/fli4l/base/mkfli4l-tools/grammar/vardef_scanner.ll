/*****************************************************************************
 *  @file grammar/vardef_scanner.l
 *  Scanner for files containing variable definitions.
 *
 *  Copyright (c) 2012-2016 The fli4l team
 *
 *  This file is part of fli4l.
 *
 *  fli4l is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  fli4l is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with fli4l.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Last Update: $Id$
 *****************************************************************************
 */

%top{
#include <string.h>
#include <stdlib.h>
#include "libmkfli4l/log.h"
#include "grammar/vardef.h"
#include "grammar/vardef_parser.h"  /* Generated by bison. */
#include "package.h"
}

%{
#include "grammar/scanner.h"
%}

%option 8bit bison-bridge bison-locations reentrant batch never-interactive
%option extra-type="struct package_file_t *"

%option noyylineno noinput nounput noyywrap
%option noyy_push_state noyy_pop_state noyy_top_state
%option nodefault noyy_scan_buffer noyy_scan_bytes noyy_scan_string
%option noyyget_extra noyyget_leng noyyget_text
%option noyyget_lineno noyyset_lineno noyyget_in
%option noyyget_out noyyset_out noyyget_lval noyyset_lval
%option noyyget_lloc noyyset_lloc noyyget_debug noyyset_debug

BOM               \xEF\xBB\xBF
/* non-array ID component */
ID_MEMBER_NAME    [A-Z][A-Z0-9]*
/* array ID component */
ID_ARRAY          %
/* ID component */
ID_COMPONENT      {ID_MEMBER_NAME}|{ID_ARRAY}
/* Keep it synchronized with "VAR_NAME_REGEX" in var/core.h! */
ID                {ID_MEMBER_NAME}(_{ID_COMPONENT})*
/* incorrect variable identifier containing lowercase letters */
WRONGID           [A-Za-z][A-Za-z0-9_%]*
/* special characters in template IDs */
TEMPLATE_SPECIAL  [][.(){},|*?+:-]
/* variable template identifiers */
TEMPLATE_ID       %[A-Z.([]([A-Z0-9_%]*{TEMPLATE_SPECIAL}+)+[A-Z0-9_%]*
WS                [ \t\v]+
LINEEND           \r?\n
/* character allowed in a single-quoted string */
SQCHAR            [^'\r\n]
/* unclosed single-quoted string */
USQSTRING         '{SQCHAR}*({LINEEND}({WS}+{SQCHAR}+)?)*
/* correct single-quoted string */
SQSTRING          {USQSTRING}'
/* character allowed in a double-quoted string */
DQCHAR            [^"\\\r\n]|(\\({LINEEND}|.))
/* unclosed double-quoted string */
UDQSTRING         \"{DQCHAR}*({LINEEND}({WS}+{DQCHAR}+)?)*
/* correct double-quoted string */
DQSTRING          {UDQSTRING}\"
/* character allowed in a comment */
CCHAR             [^\r\n]
/* a comment */
COMMENT           #{CCHAR}*({LINEEND}{WS}+#{CCHAR}*)*
/* anonymous variable type */
REGEXP            RE:[^[:space:]]+
/* digit */
DIGIT             [0-9]
/* integer number */
NUMBER            {DIGIT}+

%%

%include grammar/expr_scanner.rules

\+                      { return OPT; }
-                       { return NONE; }
{REGEXP}                { yylval->str = strdup(yytext + 3); return REGEX; }
{TEMPLATE_ID}           {
                            yylval->id = identifier_create(yytext, TRUE);
                            return TEMPLATE_ID;
                        }
{ID}                    {
                            yylval->id = identifier_create(yytext, TRUE);
                            return ID;
                        }
{WRONGID}               {
    struct location_t *location
        = location_create(yyextra, yylloc->first_line, yylloc->first_column);
    char *locstr = location_toString(location);
    log_error(
        "Error while scanning variable definitions at %s: Invalid identifier '%s'.\n",
        locstr, yytext
    );
    free(locstr);
    location_destroy(location);
                            yylval->id = identifier_create(yytext, FALSE);
                            return ID;
                        }
{SQSTRING}              {
                            char *value = strdup(yytext + 1);
                            value[strlen(value) - 1] = '\0';
                            yylval->qstr = qstr_create('\'', value, FALSE, TRUE);
                            free(value);
                            return QSTRING;
                        }
{DQSTRING}              {
                            char *value = strdup(yytext + 1);
                            value[strlen(value) - 1] = '\0';
                            yylval->qstr = qstr_create('"', value, TRUE, TRUE);
                            free(value);
                            return QSTRING;
                        }
{USQSTRING}             {
    struct location_t *location
        = location_create(yyextra, yylloc->first_line, yylloc->first_column);
    char *locstr = location_toString(location);
    log_error(
        "Error while scanning variable definitions at %s: Unclosed single-quoted string '%s'.\n",
        locstr, yytext + 1
    );
    free(locstr);
    location_destroy(location);
                            yylval->qstr = qstr_create('\'', yytext + 1, FALSE, FALSE);
                            return QSTRING;
                        }
{UDQSTRING}             {
    struct location_t *location
        = location_create(yyextra, yylloc->first_line, yylloc->first_column);
    char *locstr = location_toString(location);
    log_error(
        "Error while scanning variable definitions at %s: Unclosed double-quoted string '%s'.\n",
        locstr, yytext + 1
    );
    free(locstr);
    location_destroy(location);
                            yylval->qstr = qstr_create('"', yytext + 1, TRUE, FALSE);
                            return QSTRING;
                        }
^{BOM}?({WS}*{COMMENT}?{LINEEND})*   {}
{COMMENT}               {
                            yylval->str = comment_create(yytext);
                            return COMMENT;
                        }
{WS}                    {}
{BOM}                   {}
\r                      {}
\n                      { return NEWLINE; }
.                       {
    struct location_t *location
        = location_create(yyextra, yylloc->first_line, yylloc->first_column);
    char *locstr = location_toString(location);
    log_error(
        "Error while scanning variable definitions at %s: Unknown character '%c' (ASCII 0x%x).\n",
        locstr, yytext[0], (unsigned char) yytext[0]
    );
    free(locstr);
    location_destroy(location);
    yylval->str = strdup(yytext);
    return UNKNOWN;
}

%%
