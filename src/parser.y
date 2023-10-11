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
%token ORDER_
%token GROUP_
%token HAVING_
%token RETURN_
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
%token MIN_
%token MAX_
%token SUM_
%token COUNT_
%token AVG_
%token ASC_
%token DESC_
%token CURLY_OPEN_
%token CURLY_CLOSE_
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
%type <strval> GT_
%type <strval> LT_
%type <strval> EQ_
%type <strval> NEQ_ 
%type <intval> MIN_
%type <intval> MAX_
%type <intval> SUM_
%type <intval> COUNT_
%type <intval> AVG_  
%type <strval> LTEQ_
%type <strval> GTEQ_
%type <strval> EQGT_
%type <strval> EQLT_
%type <strval> binop
%type <intval> aggregate_function
%type <intval> INT_LITERAL_
%type <boolval> BOOL_LITERAL_


%%

Statement:
         | assignment_statement 
            { 
                  tableStack = {};
                  columnStack = {};
                  operationStack = {};
                  return 0; 
            }
         | non_assignment_statement  { return 0; }

assignment_statement: new_relation ASSIGN_ARROW_ relation 
                        {     
                              string oldName = tableStack.top();
                              tableStack.pop();
                              string newName = tableStack.top();
                              tableStack.pop();
                              tableCatalogue.renameTable(oldName, newName);
                        }

new_relation: IDENTIFIER_ 
                  { 
                        if(tableCatalogue.isTable($1))
                              cout<<"SEMANTIC ERROR: Assigned Relation already exist"<<endl;
                        tableStack.push($1);
                  }

relation: cross_product_statement
        | distinct_statement
        | join_statement
        | order_statement
        | projection_statement
        | selection_statement
        | group_by_statement
        | IDENTIFIER_ { tableStack.push($1); }
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

join_statement: JOIN_ relation relation ON_ condition
                  { if(joinQuery.checkArgs()) joinQuery.execute(); }
              ;

order_statement: ORDER_ BY_ IDENTIFIER_ BOOL_LITERAL_ ON_ IDENTIFIER_
                        {
                              orderByQuery.tableName = $6;
                              orderByQuery.updateArgList($3, $4);
                              orderByQuery.execute();
                        }

group_by_statement: GROUP_ BY_ IDENTIFIER_ FROM_ relation HAVING_ condition RETURN_ aggregate_statement
                        {
                              columnStack.push($3);
                              if(groupByQuery.checkArgs()) groupByQuery.execute();
                        }

projection_statement: PROJECT_ projection_list FROM_ relation
                    ;

projection_list: projection_list IDENTIFIER_
               | IDENTIFIER_
               ;

selection_statement: SELECT_ condition FROM_ relation
                   ;

condition: IDENTIFIER_ binop IDENTIFIER_ 
               { 
                  columnStack.push($1);
                  columnStack.push($3);
                  operationStack.push($2);
               }
         | IDENTIFIER_ binop INT_LITERAL_ 
         | aggregate_statement binop INT_LITERAL_
            {
                  intOperandStack.push($3);
                  operationStack.push($2);
            }
         ;

aggregate_statement: aggregate_function CURLY_OPEN_ IDENTIFIER_ CURLY_CLOSE_
                        {
                              aggregateFunctionStack.push({$1,$3});
                        }

aggregate_function: MIN_
                  | MAX_
                  | SUM_
                  | COUNT_
                  | AVG_  
                  ;

binop: GT_
     | GTEQ_
     | EQGT_
     | LT_
     | LTEQ_
     | EQLT_
     | EQ_  
     | NEQ_
     ;

sort_statement: SORT_ relation BY_ arg_list
              {
                sortQuery.execute(0);
                sortQuery.clear();
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