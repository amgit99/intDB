%{

#include "globals.h"
#include "semanticParser.h"
#include "executor.h"

int yylex();
void yyerror(const char* s);

%}

%union {
    int intval, argc_;
    char* strval;
    bool boolval;
}

%token ASSIGN_ARROW_
%token CROSS_
%token DISTINCT_
%token JOIN_
%token PROJECT_
%token SELECT_
%token SORT_
%token CLEAR_
%token INDEX_
%token LIST_
%token LOAD_
%token EXPORT_
%token PRINT_
%token COMPUTE_
%token CHECKSYMMETRY_
%token TRANSPOSE_
%token QUIT_
%token RENAME_
%token SOURCE_
%token MATRIX_
%token GT_
%token LT_
%token EQ_
%token NEQ_
%token LTEQ_
%token GTEQ_
%token EQGT_
%token EQLT_
%token ASC_
%token DESC_
%token HASH_
%token BTREE_
%token NOTHING_
%token COMMA_
%token ON_
%token FROM_
%token TO_
%token USING_
%token TABLES_
%token BY_
%token IN_
%token AND_
%token OR_
%token NOT_
%token IDENTIFIER_
%token INT_LITERAL_
%token BOOL_LITERAL_

%type <strval> IDENTIFIER_
%type <intval> INT_LITERAL_
%type <boolval> BOOL_LITERAL_

%%

Statement:
         | assignment_statement
         | non_assignment_statement  { return 0; }
         ;

assignment_statement: IDENTIFIER_ ASSIGN_ARROW_ relation { cout << "final assign" << endl; return 0; }
                    ;

relation: cross_product_statement { cout << "cross_product_statement" << endl; }
        | distinct_statement
        | join_statement
        | projection_statement
        | selection_statement
        | IDENTIFIER_ { cout << $1 << endl; }
        ;

non_assignment_statement: clear_statement 
                        | index_statement
                        | list_statement
                        | load_statement
                        | print_statement
                        | sort_statement
                              {
                                cout << "sort complete" << endl;
                              }
                        | QUIT_
                              { 
                                exit(0); 
                              }
                        | rename_statement
                        | SOURCE_ IDENTIFIER_
                              { 
                                if(semanticParseSOURCE($2)) 
                                    executeSOURCE($2); 
                              }
                        | COMPUTE_ IDENTIFIER_
                              { 
                                if(semanticParseCOMPUTE($2)) 
                                    executeCOMPUTE($2); 
                              }
                        | CHECKSYMMETRY_ IDENTIFIER_
                              { 
                                if(semanticParseCHECKSYMMETRY($2)) 
                                    executeCHECKSYMMETRY($2); 
                              }
                        | EXPORT_ MATRIX_ IDENTIFIER_
                              { 
                                if(semanticParseEXPORTMATRIX($3)) 
                                    executeEXPORTMATRIX($3); 
                              }
                        | TRANSPOSE_ IDENTIFIER_
                              { 
                                if(semanticParseTRANSPOSEMATRIX($2)) 
                                    executeTRANSPOSEMATRIX($2); 
                              }
                        ;

cross_product_statement: CROSS_ relation relation { cout << "cross" << endl; }
                       ;

distinct_statement: DISTINCT_ relation
                  ;

join_statement: JOIN_ relation relation ON_ IDENTIFIER_ binop IDENTIFIER_
              ;

projection_statement: PROJECT_ projection_list FROM_ relation
                    ;

projection_list: projection_list IDENTIFIER_ 
               | IDENTIFIER_
               ;

selection_statement: SELECT_ condition FROM_ relation
                   ;

condition: IDENTIFIER_ binop IDENTIFIER_ 
         | IDENTIFIER_ binop INT_LITERAL_ 
         ;

binop: GT_
     | LT_
     | EQ_
     | NEQ_ 
     | LTEQ_
     | GTEQ_
     | EQGT_
     | EQLT_
     ;

sort_statement: SORT_ relation BY_ arg_list
              {
                cout << "sort statement" << endl;
              }

arg_list: IDENTIFIER_ IN_ BOOL_LITERAL_
              { 
                cout << $1 << "  " << $3 << endl;
              }
        | IDENTIFIER_ arg_list BOOL_LITERAL_
              { 
                cout << $1 << "  " << $3 << endl;
              }

clear_statement: CLEAR_ IDENTIFIER_
               ;

index_statement: INDEX_ ON_ IDENTIFIER_ FROM_ relation USING_ indexing_strategy
               ;

rename_statement: RENAME_ IDENTIFIER_ TO_ IDENTIFIER_ FROM_ IDENTIFIER_
                          { 
                            if(semanticParseRENAME($2, $4, $6)) 
                                executeRENAME($2, $4, $6); 
                          }
                | RENAME_ MATRIX_ IDENTIFIER_ IDENTIFIER_
                          { 
                            if(semanticParseRENAMEMATRIX($3, $4)) 
                                executeRENAMEMATRIX($3, $4); 
                          }
                ;

indexing_strategy: HASH_
                 | BTREE_
                 | NOTHING_
                 ;

list_statement: LIST_ TABLES_
              ;

load_statement: LOAD_ IDENTIFIER_
                    {
                      if(semanticParseLOAD($2)) 
                          executeLOAD($2); 
                    }
              | LOAD_ MATRIX_ IDENTIFIER_
                    { 
                      if(semanticParseLOADMATRIX($3)) 
                          executeLOADMATRIX($3); 
                    }
              ;

print_statement: PRINT_ IDENTIFIER_
                    { 
                      if(semanticParsePRINT($2)) 
                          executePRINT($2); 
                    }
               | PRINT_ MATRIX_ IDENTIFIER_
                    { 
                      if(semanticParsePRINTMATRIX($3)) 
                          executePRINTMATRIX($3); 
                    }
               ;
%%

void yyerror(const char* s) {
    std::cout << "this is an Error: " << s << std::endl;
}