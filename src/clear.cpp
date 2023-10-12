#include "globals.h"

/**
 * @brief 
 * SYNTAX: CLEAR <relation_name> 
 */

bool semanticParseCLEAR(char* _tableName){
    logger.log("semanticParseCLEAR");
    string tableName = _tableName;
    //Table should exist
    if (tableCatalogue.isTable(tableName))
        return true;
    cout << "SEMANTIC ERROR: No such relation exists" << endl;
    return false;
}

void executeCLEAR(char* _tableName){
    string tableName = _tableName;
    logger.log("executeCLEAR");
    // Deleting table from the catalogue deletes all temporary files
    tableCatalogue.deleteTable(tableName);
    return;
}