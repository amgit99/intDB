#include "globals.h"
/**
 * @brief 
 * SYNTAX: R <- PROJECT column_name1, ... FROM relation_name
 */

void Projection:: clear(){
    this->resultTableName = "";
    this->projectedColumns.clear();
    this->sourceTableName = "";
    RESULT_TABLE_NAME = "";
    return;
}


bool semanticParsePROJECTION(){
    logger.log("semanticParsePROJECTION");

    projectionQuery.resultTableName = RESULT_TABLE_NAME;
    cout << "colcount: " << projectionQuery.projectedColumns.size() << endl;

    if (tableCatalogue.isTable(projectionQuery.resultTableName)){
        cout << "SEMANTIC ERROR: Resultant relation already exists" << endl;
        return false;
    }

    if (!tableCatalogue.isTable(projectionQuery.sourceTableName)){
        cout << "SEMANTIC ERROR: Relation doesn't exist" << endl;
        return false;
    }

    Table table = *tableCatalogue.getTable(projectionQuery.sourceTableName);
    for (auto col: projectionQuery.projectedColumns){
        // cout << ">> " << col << endl;
        if (!table.isColumn(col)){
            cout << "SEMANTIC ERROR: Column " << col << " doesn't exist in relation";
            return false;
        }
    }
    return true;
}

void executePROJECTION(){
    logger.log("executePROJECTION");
    Table* resultantTable = new Table(projectionQuery.resultTableName,  vector<string>(projectionQuery.projectedColumns.begin(), projectionQuery.projectedColumns.end()));
    Table table = *tableCatalogue.getTable(projectionQuery.sourceTableName);
    Cursor cursor = table.getCursor();
    vector<int> columnIndices;
    for (int columnCounter = 0; columnCounter < projectionQuery.projectedColumns.size(); columnCounter++){
        columnIndices.emplace_back(table.getColumnIndex(projectionQuery.projectedColumns[columnCounter]));
    }
    vector<int> row = cursor.getNext();
    vector<int> resultantRow(columnIndices.size(), 0);

    while (!row.empty()){

        for (int columnCounter = 0; columnCounter < columnIndices.size(); columnCounter++){
            resultantRow[columnCounter] = row[columnIndices[columnCounter]];
        }
        resultantTable->writeRow<int>(resultantRow);
        row = cursor.getNext();
    }
    resultantTable->blockify();
    tableCatalogue.insertTable(resultantTable);
    projectionQuery.clear();
    return;
}