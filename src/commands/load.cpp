#include "globals.h"
#include "semanticParser.h"
/**
 * @brief 
 * SYNTAX: LOAD relation_name
 */
// bool syntacticParseLOAD(){
//     logger.log("syntacticParseLOAD");
//     if (tokenizedQuery.size() != 2){
//         cout << "SYNTAX ERROR" << endl;
//         return false;
//     }
//     parsedQuery.queryType = LOAD;
//     parsedQuery.loadRelationName = tokenizedQuery[1];
//     return true;
// }

bool semanticParseLOAD(char* tableName){
    string _tableName = tableName;
    logger.log("semanticParseLOAD");
    if (tableCatalogue.isTable(_tableName)){
        cout << "SEMANTIC ERROR: Relation already exists" << endl;
        return false;
    }
    if (!fileExists(_tableName)){
        cout << "SEMANTIC ERROR: Data file doesn't exist" << endl;
        return false;
    }
    return true;
}

void executeLOAD(char* tableName){
    string _tableName = tableName;
    logger.log("executeLOAD");

    Table *table = new Table(_tableName);
    if (table->load()){
        tableCatalogue.insertTable(table);
        cout << "Loaded Table. Column Count: " << table->columnCount << " Row Count: " << table->rowCount << endl;
    }
    return;
}