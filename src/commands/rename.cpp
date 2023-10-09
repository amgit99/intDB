#include "globals.h"
/**
 * @brief 
 * SYNTAX: RENAME column_name TO column_name FROM relation_name
 */

bool semanticParseRENAME(char* _oldCol, char* _newCol, char* _tableName){
    logger.log("semanticParseRENAME");
    string oldCol = _oldCol, newCol = _newCol, tableName = _tableName;

    if (!tableCatalogue.isTable(tableName)){
        cout << "SEMANTIC ERROR: Relation " << tableName << " doesn't exist" << endl;
        return false;
    }
    if (!tableCatalogue.isColumnFromTable(oldCol, tableName)){
        cout << "SEMANTIC ERROR: Column " << oldCol << " doesn't exist in relation" << endl;
        return false;
    }
    if (tableCatalogue.isColumnFromTable(newCol, tableName)){
        cout << "SEMANTIC ERROR: Column with name " << newCol  << " already exists" << endl;
        return false;
    }
    return true;
}

void executeRENAME(char* _oldCol, char* _newCol, char* _tableName){
    string oldCol = _oldCol, newCol = _newCol, tableName = _tableName;
    logger.log("executeRENAME");
    Table* table = tableCatalogue.getTable(tableName);
    table->renameColumn(oldCol, newCol);
    return;
}