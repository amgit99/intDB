#include "globals.h"
#include "matrix.h"

/**
 * @brief 
 * SYNTAX: TRANSPOSE MATRIX A
 */

// bool syntacticParseTRANSPOSEMATRIX(){
//     logger.log("syntacticParseTRANSPOSEMATRIX");
//     if (tokenizedQuery.size() != 3){
//         cout << "SYNTAX ERROR" << endl;
//         return false;
//     }
//     parsedQuery.queryType = TRANSPOSE_MATRIX;
//     parsedQuery.transposeMatrixName = tokenizedQuery[2];
//     return true;
// }

bool semanticParseTRANSPOSEMATRIX(char* matrixName){
    string mat = matrixName;
    logger.log("semanticParseTRANSPOSEMATRIX");
    if (matrixCatalogue.isMatrix(mat))
        return true;
    cout << "SEMANTIC ERROR: No such matrix exists" << endl;
    return false;
}

void executeTRANSPOSEMATRIX(char* matrixName){
    string mat = matrixName;
    logger.log("executeTRANSPOSEMATRIX");
    resetBlockStats();
    Matrix* matrix = matrixCatalogue.getMatrix(mat);
    matrix->transpose();
    cout << "Total block count: " << matrix->blockCount << endl;    
    printBlockStats();
    resetBlockStats();
    return;
}