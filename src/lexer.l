%{
#include "parser.tab.h"
#include "global.h"
%}

%%
[ \t\n]+                  ; // Skip whitespace and newline
"<-"                    { return TOK_ASSIGN_ARROW; }
"CROSS"                 { return TOK_CROSS; }
"DISTINCT"              { return TOK_DISTINCT; }
"JOIN"                  { return TOK_JOIN; }
"PROJECT"               { return TOK_PROJECT; }
"SELECT"                { return TOK_SELECT; }
"SORT"                  { return TOK_SORT; }
"CLEAR"                 { return TOK_CLEAR; }
"INDEX"                 { return TOK_INDEX; }
"LIST"                  { return TOK_LIST; }
"LOAD"                  { return TOK_LOAD; }
"EXPORT"                { return TOK_EXPORT; }
"PRINT"                 { return TOK_PRINT; }
"COMPUTE"               { return TOK_COMPUTE; }
"CHECKSYMMETRY"         { return TOK_CHECKSYMMETRY; }
"TRANSPOSE"             { return TOK_TRANSPOSE; }
"QUIT"                  { return TOK_QUIT; }
"RENAME"                { return TOK_RENAME; }
"SOURCE"                { return TOK_SOURCE; }
"MATRIX"                { return TOK_MATRIX; }
">"                     { return TOK_GT; }
"<"                     { return TOK_LT; }
"=="                    { return TOK_EQ; }
"!="                    { return TOK_NEQ; }
"<="                    { return TOK_LTEQ; }
">="                    { return TOK_GTEQ; }
"=>"                    { return TOK_EQGT; }
"=<"                    { return TOK_EQLT; }
"ASC"                   { return TOK_ASC; }
"DESC"                  { return TOK_DESC; }
"HASH"                  { return TOK_HASH; }
"BTREE"                 { return TOK_BTREE; }
"NOTHING"               { return TOK_NOTHING; }
","                     { return TOK_COMMA; }
"ON"                    { return TOK_ON; }
"FROM"                  { return TOK_FROM; }
"TO"                    { return TOK_TO; }
"USING"                 { return TOK_USING; }
"TABLES"                { return TOK_TABLES; }
"BY"                    { return TOK_BY; }
"IN"                    { return TOK_IN; }
"AND"                   { return TOK_AND; }
"OR"                    { return TOK_OR; }
"NOT"                   { return TOK_NOT; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.strval = strdup(yytext); return TOK_IDENTIFIER; }
[0-9]+                  { yylval.intval = atoi(yytext); return TOK_INT_LITERAL; }
.                       { return yytext[0]; }
%%

int yywrap() {
    yyin = stdin;
    __EOF__ = 1;
    return 0;
}