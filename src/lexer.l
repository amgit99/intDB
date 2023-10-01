%{
#include "parser.tab.h"
#include "globals.h"
%}

%%
[ \t\n]+                  ; // Skip whitespace and newline
"<-"                    { return ASSIGN_ARROW_; }
"CROSS"                 { return CROSS_; }
"DISTINCT"              { return DISTINCT_; }
"JOIN"                  { return JOIN_; }
"PROJECT"               { return PROJECT_; }
"SELECT"                { return SELECT_; }
"SORT"                  { return SORT_; }
"CLEAR"                 { return CLEAR_; }
"INDEX"                 { return INDEX_; }
"LIST"                  { return LIST_; }
"LOAD"                  { return LOAD_; }
"EXPORT"                { return EXPORT_; }
"PRINT"                 { return PRINT_; }
"COMPUTE"               { return COMPUTE_; }
"CHECKSYMMETRY"         { return CHECKSYMMETRY_; }
"TRANSPOSE"             { return TRANSPOSE_; }
"QUIT"                  { return QUIT_; }
"RENAME"                { return RENAME_; }
"SOURCE"                { return SOURCE_; }
"MATRIX"                { return MATRIX_; }
">"                     { return GT_; }
"<"                     { return LT_; }
"=="                    { return EQ_; }
"!="                    { return NEQ_; }
"<="                    { return LTEQ_; }
">="                    { return GTEQ_; }
"=>"                    { return EQGT_; }
"=<"                    { return EQLT_; }
"ASC"                   { yylval.boolval = 0; return BOOL_LITERAL_; }
"DESC"                  { yylval.boolval = 1; return BOOL_LITERAL_; }
"HASH"                  { return HASH_; }
"BTREE"                 { return BTREE_; }
"NOTHING"               { return NOTHING_; }
","                     { return COMMA_; }
"ON"                    { return ON_; }
"FROM"                  { return FROM_; }
"TO"                    { return TO_; }
"USING"                 { return USING_; }
"TABLES"                { return TABLES_; }
"BY"                    { return BY_; }
"IN"                    { return IN_; }
"AND"                   { return AND_; }
"OR"                    { return OR_; }
"NOT"                   { return NOT_; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.strval = strdup(yytext); return IDENTIFIER_; }
[0-9]+                  { yylval.intval = atoi(yytext); return INT_LITERAL_; }
.                       { return yytext[0]; }
%%

int yywrap() {
    yyin = stdin;
    __EOF__ = 1;
    return 0;
}