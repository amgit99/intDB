#include "table.h"
#include "tableCatalogue.h"
#include "globals.h"

/**
 * @brief 
 * SYNTAX: EXPORT <relation_name> 
 */

bool semanticParseEXPORT(){
    logger.log("semanticParseEXPORT");
    // //Table should exist
    // if (tableCatalogue.isTable(parsedQuery.exportRelationName))
    //     return true;
    // cout << "SEMANTIC ERROR: No such relation exists" << endl;
    return false;
}

void executeEXPORT(){
    logger.log("executeEXPORT");
    // Table* table = tableCatalogue.getTable(parsedQuery.exportRelationName);
    // table->makePermanent();
    return;
}