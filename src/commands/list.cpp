#include "globals.h"
/**
 * @brief 
 * SYNTAX: LIST TABLES
 */

bool semanticParseLIST(){
    logger.log("semanticParseLIST");
    return true;
}

void executeLIST(){
    logger.log("executeLIST");
    tableCatalogue.print();
}