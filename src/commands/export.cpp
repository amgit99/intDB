#include "table.h"
#include "tableCatalogue.h"
#include "globals.h"

/**
 * @brief 
 * SYNTAX: EXPORT <relation_name> 
 */

bool semanticParseEXPORT(char* _tableName){
    logger.log("semanticParseEXPORT");
    string tableName = _tableName;
    //Table should exist
    if (tableCatalogue.isTable(tableName))
        return true;
    cout << "SEMANTIC ERROR: No such relation exists" << endl;
    return false;
}

void executeEXPORT(char* _tableName){
    string tableName = _tableName;
    logger.log("executeEXPORT");
    Table* table = tableCatalogue.getTable(tableName);
    table->makePermanent();
    return;
}