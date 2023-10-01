#include "globals.h"
/**
 * @brief 
 * SYNTAX: R <- JOIN relation_name1, relation_name2 ON column_name1 bin_op column_name2
 */

bool semanticParseJOIN(){
    logger.log("semanticParseJOIN");

    // if (tableCatalogue.isTable(parsedQuery.joinResultRelationName)){
    //     cout << "SEMANTIC ERROR: Resultant relation already exists" << endl;
    //     return false;
    // }

    // if (!tableCatalogue.isTable(parsedQuery.joinFirstRelationName) || !tableCatalogue.isTable(parsedQuery.joinSecondRelationName)){
    //     cout << "SEMANTIC ERROR: Relation doesn't exist" << endl;
    //     return false;
    // }

    // if (!tableCatalogue.isColumnFromTable(parsedQuery.joinFirstColumnName, parsedQuery.joinFirstRelationName) || !tableCatalogue.isColumnFromTable(parsedQuery.joinSecondColumnName, parsedQuery.joinSecondRelationName)){
    //     cout << "SEMANTIC ERROR: Column doesn't exist in relation" << endl;
    //     return false;
    // }
    return true;
}

void executeJOIN(){
    logger.log("executeJOIN");
    return;
}