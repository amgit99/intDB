#include "globals.h"
/**
 * @brief 
 * SYNTAX: RENAME column_name TO column_name FROM relation_name
 */

bool semanticParseRENAME(char* _oldCol, char* _newCol, char* _tableName){
    string oldCol = _oldCol, newCol = _oldCol, tableName = _tableName;
    // logger.log("semanticParseRENAME");

    // if (!tableCatalogue.isTable(parsedQuery.renameRelationName)){
    //     cout << "SEMANTIC ERROR: Relation doesn't exist" << endl;
    //     return false;
    // }
    // if (!tableCatalogue.isColumnFromTable(parsedQuery.renameFromColumnName, parsedQuery.renameRelationName)){
    //     cout << "SEMANTIC ERROR: Column doesn't exist in relation" << endl;
    //     return false;
    // }
    // if (tableCatalogue.isColumnFromTable(parsedQuery.renameToColumnName, parsedQuery.renameRelationName)){
    //     cout << "SEMANTIC ERROR: Column with name already exists" << endl;
    //     return false;
    // }
    return true;
}

void executeRENAME(char* _oldCol, char* _newCol, char* _tableName){
    // string oldCol = _oldCol, newCol = _oldCol, tableName = _tableName;
    // logger.log("executeRENAME");
    // Table* table = tableCatalogue.getTable(tableName);
    // table->renameColumn(oldCol, newCol);
    return;
}