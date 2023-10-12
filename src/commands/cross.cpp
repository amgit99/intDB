#include "globals.h"
#include "table.h"
#include "cross.h"

/**
 * @brief 
 * SYNTAX: R <- CROSS relation_name relation_name
 */

void Cross::clear(){
    this->resultTableName = "";
    this->table1Name = "";
    this->table2Name = "";
    RESULT_TABLE_NAME = "";
    return;
}

bool semanticParseCROSS(){
    logger.log("semanticParseCROSS");
    //Table shouldn't exist
    if (tableCatalogue.isTable(crossQuery.resultTableName)){
        cout << "SEMANTIC ERROR: Result relation " << crossQuery.resultTableName << " already exists" << endl;
        return false;
    }
    // Table should exist
    if (!tableCatalogue.isTable(crossQuery.table1Name)){
        cout << "SEMANTIC ERROR: Relation " << crossQuery.table1Name << " doesn't exist" << endl;
        return false;
    }
    if (!tableCatalogue.isTable(crossQuery.table2Name)){
        cout << "SEMANTIC ERROR: Relation " << crossQuery.table2Name << " doesn't exist" << endl;
        return false;
    }
    return true;
}

void executeCROSS(){
    logger.log("executeCROSS");
    string table1Name = crossQuery.table1Name;
    string table2Name = crossQuery.table2Name;

    Table table1 = *(tableCatalogue.getTable(table1Name));
    Table table2 = *(tableCatalogue.getTable(table2Name));

    vector<string> columns;

    //If both tables are the same i.e. CROSS a a, then names are indexed as a1 and a2
    if(table1.tableName == table2.tableName){
        table1Name += "1";
        table2Name += "2";
    }

    //Creating list of column names
    for (int columnCounter = 0; columnCounter < table1.columnCount; columnCounter++){
        string columnName = table1.columns[columnCounter];
        if (table2.isColumn(columnName)){
            columnName = table1Name + "_" + columnName;
        }
        columns.emplace_back(columnName);
    }

    for (int columnCounter = 0; columnCounter < table2.columnCount; columnCounter++){
        string columnName = table2.columns[columnCounter];
        if (table1.isColumn(columnName)){
            columnName = table2Name + "_" + columnName;
        }
        columns.emplace_back(columnName);
    }

    Table *resultantTable = new Table(crossQuery.resultTableName, columns);

    Cursor cursor1 = table1.getCursor();
    Cursor cursor2 = table2.getCursor();

    vector<int> row1 = cursor1.getNext();
    vector<int> row2;
    vector<int> resultantRow;
    resultantRow.reserve(resultantTable->columnCount);

    while (!row1.empty()){

        cursor2 = table2.getCursor();
        row2 = cursor2.getNext();
        while (!row2.empty()){
            resultantRow = row1;
            resultantRow.insert(resultantRow.end(), row2.begin(), row2.end());
            resultantTable->writeRow<int>(resultantRow);
            row2 = cursor2.getNext();
        }
        row1 = cursor1.getNext();
    }
    resultantTable->blockify();
    tableCatalogue.insertTable(resultantTable);
    crossQuery.clear();
    return;
}