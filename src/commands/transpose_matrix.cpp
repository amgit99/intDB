#include "global.h"

/**
 * @brief 
 * SYNTAX: TRANSPOSE MATRIX A
 */

bool syntacticParseTRANSPOSEMATRIX(){
    logger.log("syntacticParseTRANSPOSEMATRIX");
    if (tokenizedQuery.size() != 3){
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType = TRANSPOSE_MATRIX;
    parsedQuery.transposeMatrixName = tokenizedQuery[2];
    return true;
}

bool semanticParseTRANSPOSEMATRIX(){
    logger.log("semanticParseTRANSPOSEMATRIX");
    if (matrixCatalogue.isMatrix(parsedQuery.transposeMatrixName))
        return true;
    cout << "SEMANTIC ERROR: No such matrix exists" << endl;
    return false;
}

void executeTRANSPOSEMATRIX(){
    logger.log("executeTRANSPOSEMATRIX");
    resetBlockStats();
    Matrix* matrix = matrixCatalogue.getMatrix(parsedQuery.transposeMatrixName);
    matrix->transpose();
    cout << "Total block count: " << matrix->blockCount << endl;    
    printBlockStats();
    resetBlockStats();
    return;
}