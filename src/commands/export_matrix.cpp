#include "globals.h"
#include "matrix.h"

/**
 * @brief 
 * SYNTAX: EXPORT MATRIX A
 */

bool semanticParseEXPORTMATRIX(char* matrixName){
    string mat = matrixName;
    logger.log("semanticParseEXPORTMATRIX");
    if (matrixCatalogue.isMatrix(mat))
        return true;
    cout << "SEMANTIC ERROR: No such matrix exists" << endl;
    return false;
}

void executeEXPORTMATRIX(char* matrixName){
    string mat = matrixName;
    logger.log("executeEXPORTMATRIX");
    resetBlockStats();
    Matrix* matrix = matrixCatalogue.getMatrix(mat);
    matrix->exportMatrix(matrix->rowCount, matrix->columnCount);
    cout << "Matrix exported." << endl;
    cout << "Total block count: " << matrix->blockCount << endl;
    printBlockStats();
    resetBlockStats();
    return;
}