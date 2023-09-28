#include "global.h"

/**
 * @brief 
 * SYNTAX: EXPORT MATRIX A
 */

// bool syntacticParseEXPORTMATRIX(){
//     logger.log("syntacticParseEXPORTMATRIX");
//     if (tokenizedQuery.size() != 3){
//         cout << "SYNTAX ERROR" << endl;
//         return false;
//     }
//     parsedQuery.queryType = EXPORT_MATRIX;
//     parsedQuery.exportMatrixName = tokenizedQuery[2];
//     return true;
// }

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