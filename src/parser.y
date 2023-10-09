%{

#include "globals.h"
#include "executor.h"

int yylex();
void yyerror(const char* s);

%}

%union {
    int intval;
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
%type <strval> binop
%type <strval> GT_
%type <strval> LT_
%type <strval> EQ_
%type <strval> NEQ_
%type <strval> LTEQ_
%type <strval> GTEQ_
%type <strval> EQGT_
%type <strval> EQLT_
%type <intval> INT_LITERAL_
%type <boolval> BOOL_LITERAL_

%%

Statement:
         | assignment_statement
         | non_assignment_statement  { return 0; }
         ;

assignment_statement: result_table_name ASSIGN_ARROW_ relation 
                        {
                          cout << "final assign" << endl; return 0; 
                        }
                    ;

result_table_name: IDENTIFIER_
                    {
                      cout << "result: " << $1 << endl;
                      RESULT_TABLE_NAME = $1;
                    }
                 ;

relation: cross_product_statement { cout << "cross_product_statement" << endl; }
        | distinct_statement
        | join_statement
        | projection_statement
        | selection_statement
        | IDENTIFIER_ { evaluatedTable.push($1); }
        ;

non_assignment_statement: clear_statement 
                        | index_statement
                        | list_statement
                        | load_statement
                        | print_statement
                        | export_statement
                        | sort_statement
                              {
                                cout << "sort complete" << endl;
                              }
                        | QUIT_
                              { 
                                cout << "matching here" << endl;
                                return 69; 
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
                        | TRANSPOSE_ IDENTIFIER_
                              { 
                                if(semanticParseTRANSPOSEMATRIX($2)) 
                                    executeTRANSPOSEMATRIX($2); 
                              }
                        ;


cross_product_statement: CROSS_ IDENTIFIER_ IDENTIFIER_
                              {
                                cout << "cross" << endl;
                                crossQuery.resultTableName = RESULT_TABLE_NAME;
                                crossQuery.table1Name = $2;
                                crossQuery.table2Name = $3;
                                if(semanticParseCROSS())
                                    executeCROSS();
                              }
                       ;

distinct_statement: DISTINCT_ relation
                  ;

join_statement: JOIN_ relation relation ON_ IDENTIFIER_ binop IDENTIFIER_
              ;

projection_statement: PROJECT_ projection_list FROM_ IDENTIFIER_
                        {
                          projectionQuery.sourceTableName = $4;
                          if(semanticParsePROJECTION())
                              executePROJECTION();
                        }
                    ;

projection_list: projection_list IDENTIFIER_ 
                  {
                    // cout << $2 << endl;
                    projectionQuery.projectedColumns.push_back($2);
                  }
               | IDENTIFIER_
                  {
                    // cout << $1 << endl;
                    projectionQuery.projectedColumns.push_back($1);
                  }
               ;

selection_statement: SELECT_ condition FROM_ IDENTIFIER_
                      {
                        selectionQuery.sourceTableName = $4;
                        if(semanticParseSELECTION())
                            executeSELECTION();
                      }
                   ;

condition: IDENTIFIER_ binop IDENTIFIER_ 
            {
              CONDITION_L_COLUMN_NAME = $1;
              CONDITION_BINOP = $2;
              selectionQuery.selectType = COLUMN;
              CONDITION_R_COLUMN_NAME = $3;
            }
         | IDENTIFIER_ binop INT_LITERAL_ 
            {
              CONDITION_L_COLUMN_NAME = $1;
              CONDITION_BINOP = $2;
              selectionQuery.selectType = INT_LITERAL;
              CONDITION_R_INTVAL = $3;
            }
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
                sortQuery.execute();
              }

arg_list: IDENTIFIER_ IN_ BOOL_LITERAL_
              { 
                sortQuery.updateArgList($1, $3);
              }
        | IDENTIFIER_ arg_list BOOL_LITERAL_
              { 
                sortQuery.updateArgList($1, $3);
              }

clear_statement: CLEAR_ IDENTIFIER_
                        { 
                          if(semanticParseCLEAR($2)) 
                              executeCLEAR($2); 
                        }
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
                  {
                    executeLIST();
                  }
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


export_statement: EXPORT_ IDENTIFIER_
                        { 
                              if(semanticParseEXPORT($2)) 
                              executeEXPORT($2); 
                        }
                | EXPORT_ MATRIX_ IDENTIFIER_
                        { 
                              if(semanticParseEXPORTMATRIX($3)) 
                              executeEXPORTMATRIX($3); 
                        }

%%

void yyerror(const char* s) {
    std::cout << "this is an Error: " << s << std::endl;
}