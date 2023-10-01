#include "globals.h"
/**
 * @brief 
 * SYNTAX: INDEX ON column_name FROM relation_name USING indexing_strategy
 * indexing_strategy: ASC | DESC | NOTHING
 */

bool semanticParseINDEX(){
    logger.log("semanticParseINDEX");
    // if (!tableCatalogue.isTable(parsedQuery.indexRelationName)){
    //     cout << "SEMANTIC ERROR: Relation doesn't exist" << endl;
    //     return false;
    // }
    // if (!tableCatalogue.isColumnFromTable(parsedQuery.indexColumnName, parsedQuery.indexRelationName)){
    //     cout << "SEMANTIC ERROR: Column doesn't exist in relation" << endl;
    //     return false;
    // }
    // Table* table = tableCatalogue.getTable(parsedQuery.indexRelationName);
    // if(table->indexed){
    //     cout << "SEMANTIC ERROR: Table already indexed" << endl;
    //     return false;
    // }
    return true;
}

void executeINDEX(){
    logger.log("executeINDEX");
    return;
}