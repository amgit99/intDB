#include "global.h"

/**
 * @brief 
 * SYNTAX: EXPORT MATRIX A
 */

bool syntacticParseEXPORTMATRIX(){
    logger.log("syntacticParseEXPORTMATRIX");
    if (tokenizedQuery.size() != 3){
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType = EXPORT_MATRIX;
    parsedQuery.exportMatrixName = tokenizedQuery[2];
    return true;
}

bool semanticParseEXPORTMATRIX(){
    logger.log("semanticParseEXPORTMATRIX");
    if (matrixCatalogue.isMatrix(parsedQuery.exportMatrixName))
        return true;
    cout << "SEMANTIC ERROR: No such matrix exists" << endl;
    return false;
}

void executeEXPORTMATRIX(){
    logger.log("executeEXPORTMATRIX");
    resetBlockStats();
    Matrix* matrix = matrixCatalogue.getMatrix(parsedQuery.exportMatrixName);
    matrix->exportMatrix(matrix->rowCount, matrix->columnCount);
    cout << "Matrix exported." << endl;
    printBlockStats();
    resetBlockStats();
    return;
}