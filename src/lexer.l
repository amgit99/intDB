%{
#include "parser.tab.h"
#include "globals.h"
%}

%%
[ \t\n]+                ; // Skip whitespace and newline
"<-"                    { return ASSIGN_ARROW_; }
"CROSS"                 { return CROSS_; }
"DISTINCT"              { return DISTINCT_; }
"JOIN"                  { return JOIN_; }
"PROJECT"               { return PROJECT_; }
"SELECT"                { return SELECT_; }
"SORT"                  { return SORT_; }
"ORDER"                 { return ORDER_; }
"GROUP"                 { return GROUP_; }
"HAVING"                { return HAVING_; }
"RETURN"                { return RETURN_; }
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
">"                     { yylval.strval = strdup(yytext); return GT_; }
"<"                     { yylval.strval = strdup(yytext); return LT_; }
"=="                    { yylval.strval = strdup(yytext); return EQ_; }
"!="                    { yylval.strval = strdup(yytext); return NEQ_; }
"<="                    { yylval.strval = strdup(yytext); return LTEQ_; }
">="                    { yylval.strval = strdup(yytext); return GTEQ_; }
"=>"                    { yylval.strval = strdup(yytext); return EQGT_; }
"=<"                    { yylval.strval = strdup(yytext); return EQLT_; }
"("                     { return CURLY_OPEN_  ;}
")"                     { return CURLY_CLOSE_ ;}
"MIN"                   { yylval.intval = 1; return MIN_; }
"MAX"                   { yylval.intval = 2; return MAX_; }
"SUM"                   { yylval.intval = 3; return SUM_; }
"COUNT"                 { yylval.intval = 4; return COUNT_; }
"AVG"                   { yylval.intval = 5; return AVG_; }
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