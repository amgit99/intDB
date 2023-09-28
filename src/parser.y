%{
#include "global.h"

int yylex();
void yyerror(const char* s);
%}

%union {
    int intval;
    char* strval;
}

%token TOK_ASSIGN_ARROW TOK_CROSS TOK_DISTINCT TOK_JOIN TOK_PROJECT TOK_SELECT TOK_SORT TOK_CLEAR TOK_INDEX
%token TOK_LIST TOK_LOAD TOK_PRINT TOK_COMPUTE TOK_TRANSPOSE TOK_QUIT TOK_RENAME TOK_SOURCE TOK_IDENTIFIER TOK_INT_LITERAL
%token TOK_GT TOK_LT TOK_EQ TOK_NEQ TOK_LTEQ TOK_GTEQ TOK_EQGT TOK_EQLT TOK_MATRIX TOK_EOL TOK_EXPORT TOK_CHECKSYMMETRY
%token TOK_ASC TOK_DESC TOK_HASH TOK_BTREE TOK_NOTHING TOK_COMMA TOK_ON TOK_FROM TOK_TO TOK_USING TOK_TABLES TOK_BY TOK_IN TOK_AND TOK_OR TOK_NOT

%type <strval> TOK_IDENTIFIER
%type <intval> TOK_INT_LITERAL

%%

Statement:
    | RelationAssign
    | NonAssignmentStatement
    ;

RelationAssign:
      TOK_IDENTIFIER TOK_ASSIGN_ARROW AssignmentStatement
    ;

AssignmentStatement:
      CrossProductStatement
    | TOK_DISTINCT TOK_IDENTIFIER
    | JoinStatement
    | ProjectionStatement
    | SelectionStatement
    | SortStatement
    ;

NonAssignmentStatement:
      TOK_CLEAR TOK_IDENTIFIER

    | TOK_INDEX TOK_ON TOK_IDENTIFIER TOK_FROM TOK_IDENTIFIER TOK_USING IndexingStrategy

    | TOK_LIST TOK_TABLES
              { executeLIST(); return 0; }

    | TOK_LOAD TOK_IDENTIFIER

    | TOK_PRINT TOK_IDENTIFIER
              { if(semanticParsePRINT($2)) executePRINT($2); return 0; }

    | TOK_LOAD TOK_MATRIX TOK_IDENTIFIER  
              { if(semanticParseLOADMATRIX($3)) executeLOADMATRIX($3); return 0;}

    | TOK_PRINT TOK_MATRIX TOK_IDENTIFIER
              { if(semanticParsePRINTMATRIX($3)) executePRINTMATRIX($3); return 0;}
    
    | TOK_TRANSPOSE TOK_IDENTIFIER
              { if(semanticParseTRANSPOSEMATRIX($2)) executeTRANSPOSEMATRIX($2); return 0;}

    | TOK_EXPORT TOK_MATRIX TOK_IDENTIFIER
              { if(semanticParseEXPORTMATRIX($3)) executeEXPORTMATRIX($3); return 0;}
    
    | TOK_CHECKSYMMETRY TOK_IDENTIFIER
              { if(semanticParseCHECKSYMMETRY($2)) executeCHECKSYMMETRY($2); return 0; }

    | TOK_COMPUTE TOK_IDENTIFIER
              { if(semanticParseCOMPUTE($2)) executeCOMPUTE($2); return 0;}

    | TOK_QUIT
              { exit(0); }

    | RenameStatement

    | TOK_SOURCE TOK_IDENTIFIER
              { if(semanticParseSOURCE($2)) executeSOURCE($2); return 0;}
    ;

CrossProductStatement:
      TOK_CROSS TOK_IDENTIFIER TOK_IDENTIFIER
    ;

JoinStatement:
      TOK_JOIN TOK_IDENTIFIER TOK_COMMA TOK_IDENTIFIER TOK_ON TOK_IDENTIFIER binop TOK_IDENTIFIER
    ;

ProjectionStatement:
      TOK_PROJECT ProjectionList TOK_FROM TOK_IDENTIFIER
    ;

ProjectionList:
      ProjectionList TOK_COMMA TOK_IDENTIFIER
    | TOK_IDENTIFIER
    ;

SelectionStatement:
      TOK_SELECT Condition TOK_FROM TOK_IDENTIFIER
    ;

Condition:
      TOK_IDENTIFIER binop TOK_IDENTIFIER
    | TOK_IDENTIFIER binop TOK_INT_LITERAL
    ;

IndexingStrategy:
      TOK_HASH
    | TOK_BTREE
    | TOK_NOTHING
    ;

SortStatement:
      TOK_SORT TOK_IDENTIFIER TOK_BY TOK_IDENTIFIER TOK_IN SortingOrder
    ;

SortingOrder:
      TOK_ASC
    | TOK_DESC
    ;

RenameStatement:
      TOK_RENAME TOK_IDENTIFIER TOK_TO TOK_IDENTIFIER TOK_FROM TOK_IDENTIFIER
              { if(semanticParseRENAME($2, $4, $6)) executeRENAME($2, $4, $6); return 0; }

    | TOK_RENAME TOK_MATRIX TOK_IDENTIFIER TOK_IDENTIFIER
              { if(semanticParseRENAMEMATRIX($3, $4)) executeRENAMEMATRIX($3, $4); return 0;}
    ;

binop:
      TOK_GT
    | TOK_LT
    | TOK_EQ
    | TOK_NEQ
    | TOK_GTEQ
    | TOK_LTEQ
    | TOK_EQLT
    | TOK_EQGT

%%

void yyerror(const char* s) {
    std::cout << "this is an Error: " << s << std::endl;
}
