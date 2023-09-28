#include "global.h"
/**
 * @brief 
 * SYNTAX: PRINT relation_name
 */
// bool syntacticParsePRINT(){
//     logger.log("syntacticParsePRINT");
//     if (tokenizedQuery.size() != 2){
//         cout << "SYNTAX ERROR" << endl;
//         return false;
//     }
//     parsedQuery.queryType = PRINT;
//     parsedQuery.printRelationName = tokenizedQuery[1];
//     return true;
// }

bool semanticParsePRINT(char* _tableName){
    string tableName = _tableName;
    logger.log("semanticParsePRINT");
    if (!tableCatalogue.isTable(tableName)){
        cout << "SEMANTIC ERROR: Relation doesn't exist" << endl;
        return false;
    }
    return true;
}

void executePRINT(char* _tableName){
    string tableName = _tableName;
    logger.log("executePRINT");
    Table* table = tableCatalogue.getTable(tableName);
    table->print();
    return;
}
