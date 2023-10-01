#include "globals.h"
/**
 * @brief 
 * SYNTAX: R <- SELECT column_name bin_op [column_name | int_literal] FROM relation_name
 */

bool semanticParseSELECTION(){
    logger.log("semanticParseSELECTION");

    // if (tableCatalogue.isTable(parsedQuery.selectionResultRelationName)){
    //     cout << "SEMANTIC ERROR: Resultant relation already exists" << endl;
    //     return false;
    // }

    // if (!tableCatalogue.isTable(parsedQuery.selectionRelationName)){
    //     cout << "SEMANTIC ERROR: Relation doesn't exist" << endl;
    //     return false;
    // }

    // if (!tableCatalogue.isColumnFromTable(parsedQuery.selectionFirstColumnName, parsedQuery.selectionRelationName)){
    //     cout << "SEMANTIC ERROR: Column doesn't exist in relation" << endl;
    //     return false;
    // }

    // if (parsedQuery.selectType == COLUMN){
    //     if (!tableCatalogue.isColumnFromTable(parsedQuery.selectionSecondColumnName, parsedQuery.selectionRelationName)){
    //         cout << "SEMANTIC ERROR: Column doesn't exist in relation" << endl;
    //         return false;
    //     }
    // }
    return true;
}

// bool evaluateBinOp(int value1, int value2, BinaryOperator binaryOperator){
//     switch (binaryOperator){
//     case LESS_THAN:
//         return (value1 < value2);
//     case GREATER_THAN:
//         return (value1 > value2);
//     case LEQ:
//         return (value1 <= value2);
//     case GEQ:
//         return (value1 >= value2);
//     case EQUAL:
//         return (value1 == value2);
//     case NOT_EQUAL:
//         return (value1 != value2);
//     default:
//         return false;
//     }
// }

void executeSELECTION(){
    logger.log("executeSELECTION");

    // Table table = *tableCatalogue.getTable(parsedQuery.selectionRelationName);
    // Table* resultantTable = new Table(parsedQuery.selectionResultRelationName, table.columns);
    // Cursor cursor = table.getCursor();
    // vector<int> row = cursor.getNext();
    // int firstColumnIndex = table.getColumnIndex(parsedQuery.selectionFirstColumnName);
    // int secondColumnIndex;
    // if (parsedQuery.selectType == COLUMN)
    //     secondColumnIndex = table.getColumnIndex(parsedQuery.selectionSecondColumnName);
    // while (!row.empty()){

    //     int value1 = row[firstColumnIndex];
    //     int value2;
    //     if (parsedQuery.selectType == INT_LITERAL)
    //         value2 = parsedQuery.selectionIntLiteral;
    //     else
    //         value2 = row[secondColumnIndex];
    //     if (evaluateBinOp(value1, value2, parsedQuery.selectionBinaryOperator))
    //         resultantTable->writeRow<int>(row);
    //     row = cursor.getNext();
    // }
    // if(resultantTable->blockify())
    //     tableCatalogue.insertTable(resultantTable);
    // else{
    //     cout<<"Empty Table"<<endl;
    //     resultantTable->unload();
    //     delete resultantTable;
    // }
    return;
}