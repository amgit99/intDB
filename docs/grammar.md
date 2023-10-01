# Relational Algebra Grammar

## Grammar  
The relation produce some relation that is stored in the catlogue and name is stored on the stack.

```
Statement ::= assignment_statement
            | non_assignment_statement

assignment_statement ::= RELATION_NAME <- relation

relation ::=  cross_product_statement
           | distinct_statement
           | join_statement
           | projection_statement
           | selection_statement
           | sort_statement
           | RELATION_NAME

non_assignment_statement ::=  clear_statement 
                           | index_statement
                           | list_statement
                           | load_statement
                           | print_statement
                           | quit_statement
                           | rename_statement
                           | source_statement
                           | compute_statement
                           | transpose_statement

cross_product_statement ::= CROSS relation relation

distinct_statement ::= DISTINCT relation

join_statement ::= JOIN relation relation ON COLUMN_NAME bin_op COLUMN_NAME

projection_statement ::= PROJECT projection_list FROM relation

projection_list ::= projection_list COLUMN_NAME 
                  | COLUMN_NAME

selection_statement ::= SELECT condition FROM relation

condition ::= COLUMN_NAME binop COLUMN_NAME 
            | COLUMN_NAME binop INT_LITERAL 

binop ::= > | < | == | != | <= | >= | => | =<

sort_statement ::= SORT relation BY COLUMN_NAME IN sorting_order

sorting_order ::= ASC 
                | DESC

clear_statement ::= CLEAR RELATION_NAME

index_statement ::= INDEX ON COLUMN_NAME FROM relation USING indexing_strategy

rename_statement ::= RENAME COLUMN_NAME TO COLUMN_NAME FROM RELATION_NAME
                   | RENAME MATRIX CURRENT_MATRIX_NAME NEW_MATRIX_NAME

indexing_strategy ::= HASH 
                    | BTREE 
                    | NOTHING

list_statement ::= LIST TABLES;

load_statement ::= LOAD RELATION_NAME
                 | LOAD MATRIX MATRIX_NAME

print_statement ::= PRINT relation
                  | PRINT MATRIX MATRIX_NAME

compute_statement ::= COMPUTE MATRIX_NAME

transpose_statement ::= TRANSPOSE MATRIX_NAME

quit_statement ::= QUIT

source_statement ::= SOURCE FILE_NAME

```