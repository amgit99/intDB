#include "globals.h"
/**
 * @brief 
 * SYNTAX: R <- SELECT column_name bin_op [column_name | int_literal] FROM relation_name
 */

void Selection::clear(){
    this->resultTableName = "";
    this->binop = "";
    this->lcolumnName = "";
    this->rIntValue = 0;
    this->rcolumnName = "";
    this->sourceTableName = "";
    RESULT_TABLE_NAME = "";
    CONDITION_L_COLUMN_NAME = "";
    CONDITION_BINOP = "";
    CONDITION_R_INTVAL = 0;
    CONDITION_R_COLUMN_NAME = "";
    return;
}

bool semanticParseSELECTION(){
    logger.log("semanticParseSELECTION");

    selectionQuery.resultTableName = RESULT_TABLE_NAME;
    selectionQuery.lcolumnName = CONDITION_L_COLUMN_NAME;
    selectionQuery.binop = CONDITION_BINOP;
    selectionQuery.rIntValue = CONDITION_R_INTVAL;
    selectionQuery.rcolumnName = CONDITION_R_COLUMN_NAME;

    if (tableCatalogue.isTable(selectionQuery.resultTableName)){
        cout << "SEMANTIC ERROR: Resultant relation "<< selectionQuery.resultTableName << " already exists" << endl;
        return false;
    }

    if (!tableCatalogue.isTable(selectionQuery.sourceTableName)){
        cout << "SEMANTIC ERROR: Relation " << selectionQuery.sourceTableName << " doesn't exist" << endl;
        return false;
    }

    if (!tableCatalogue.isColumnFromTable(selectionQuery.lcolumnName, selectionQuery.sourceTableName)){
        cout << "SEMANTIC ERROR: Column " << selectionQuery.lcolumnName << " doesn't exist in relation "<< selectionQuery.sourceTableName << endl;
        return false;
    }

    if (selectionQuery.selectType == COLUMN){
        if (!tableCatalogue.isColumnFromTable(selectionQuery.rcolumnName, selectionQuery.sourceTableName)){
            cout << "SEMANTIC ERROR: Column doesn't exist in relation" << endl;
            return false;
        }
    }
    return true;
}

bool evaluateBinOp(int value1, int value2, BinaryOperator binaryOperator){
    switch (binaryOperator){
    case LESS_THAN:
        return (value1 < value2);
    case GREATER_THAN:
        return (value1 > value2);
    case LEQ:
        return (value1 <= value2);
    case GEQ:
        return (value1 >= value2);
    case EQUAL:
        return (value1 == value2);
    case NOT_EQUAL:
        return (value1 != value2);
    default:
        return false;
    }
}

BinaryOperator binopStringToBinaryOperator(string binop){
    if (binop == "<")
        return LESS_THAN;
    else if (binop == ">")
        return GREATER_THAN;
    else if (binop == ">=" || binop == "=>")
        return GEQ;
    else if (binop == "<=" || binop == "=<")
        return LEQ;
    else if (binop == "==")
        return EQUAL;
    else if (binop == "!=")
        return NOT_EQUAL;
    else
        return NO_BINOP_CLAUSE;
}

void executeSELECTION(){
    logger.log("executeSELECTION");

    Table table = *tableCatalogue.getTable(selectionQuery.sourceTableName);
    Table* resultantTable = new Table(selectionQuery.resultTableName, table.columns);
    Cursor cursor = table.getCursor();
    vector<int> row = cursor.getNext();
    int lColumnIndex = table.getColumnIndex(selectionQuery.lcolumnName);
    int rColumnIndex;
    if (selectionQuery.selectType == COLUMN)
        rColumnIndex = table.getColumnIndex(selectionQuery.rcolumnName);
    while (!row.empty()){
        int value1 = row[lColumnIndex];
        int value2;
        if (selectionQuery.selectType == INT_LITERAL)
            value2 = selectionQuery.rIntValue;
        else
            value2 = row[rColumnIndex];
        if (evaluateBinOp(value1, value2, binopStringToBinaryOperator(selectionQuery.binop)))
            resultantTable->writeRow<int>(row);
        row = cursor.getNext();
    }
    if(resultantTable->blockify())
        tableCatalogue.insertTable(resultantTable);
    else{
        cout << "Empty Table" << endl;
        resultantTable->unload();
        delete resultantTable;
    }
    selectionQuery.clear();
    return;
}