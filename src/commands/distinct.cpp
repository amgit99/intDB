#include "tableCatalogue.h"
#include "globals.h"

/**
 * @brief 
 * SYNTAX: R <- DISTINCT relation_name
 */

bool semanticParseDISTINCT(){
    // logger.log("semanticParseDISTINCT");
    // //The resultant table shouldn't exist and the table argument should
    // if (tableCatalogue.isTable(parsedQuery.distinctResultRelationName)){
    //     cout << "SEMANTIC ERROR: Resultant relation already exists" << endl;
    //     return false;
    // }

    // if (!tableCatalogue.isTable(parsedQuery.distinctRelationName)){
    //     cout << "SEMANTIC ERROR: Relation doesn't exist" << endl;
    //     return false;
    // }
    return true;
}

void executeDISTINCT(){
    logger.log("executeDISTINCT");
    return;
}