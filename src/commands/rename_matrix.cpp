#include "global.h"
/**
 * @brief 
 * SYNTAX: RENAME MATRIX A B
 */
bool syntacticParseRENAMEMATRIX(){
    logger.log("syntacticParseRENAMEMATRIX");
    if (tokenizedQuery.size() != 4){
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType = RENAME_MATRIX;
    parsedQuery.printMatrixName = tokenizedQuery[2];
    parsedQuery.renameMatrixName = tokenizedQuery[3];
    // cout << parsedQuery.printMatrixName << "   " << parsedQuery.renameMatrixName << endl;
    return true;
}

bool semanticParseRENAMEMATRIX(){
    logger.log("semanticParseRENAMEMATRIX");

    if (!matrixCatalogue.isMatrix(parsedQuery.printMatrixName)){
        cout << "SEMANTIC ERROR: Matrix doesn't exist" << endl;
        return false;
    }
    return true;
}

void executeRENAMEMATRIX(){
    logger.log("executeRENAMEMATRIX");
    resetBlockStats();
    Matrix* matrix = matrixCatalogue.getMatrix(parsedQuery.printMatrixName);
    matrix->rename(parsedQuery.renameMatrixName);
    cout << "Total block count: " << matrix->blockCount << endl;    
    printBlockStats();
    resetBlockStats();
    return;
}