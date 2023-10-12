#include "globals.h"
#include "matrix.h"
/**
 * @brief 
 * SYNTAX: RENAME MATRIX A B
 */
// bool syntacticParseRENAMEMATRIX(){
//     logger.log("syntacticParseRENAMEMATRIX");
//     if (tokenizedQuery.size() != 4){
//         cout << "SYNTAX ERROR" << endl;
//         return false;
//     }
//     parsedQuery.queryType = RENAME_MATRIX;
//     parsedQuery.printMatrixName = tokenizedQuery[2];
//     parsedQuery.renameMatrixName = tokenizedQuery[3];
//     return true;
// }

bool semanticParseRENAMEMATRIX(char* oldName, char* newName){
    string oldMat = oldName, newMat = newName;
    logger.log("semanticParseRENAMEMATRIX");

    if (!matrixCatalogue.isMatrix(oldMat)){
        cout << "SEMANTIC ERROR: Matrix doesn't exist" << endl;
        return false;
    }
    if (matrixCatalogue.isMatrix(newMat)){
        cout << "SEMANTIC ERROR: Matrix of this name already exists" << endl;
        return false;
    }
    return true;
}

void executeRENAMEMATRIX(char* oldName, char* newName){
    string oldMat = oldName, newMat = newName;
    logger.log("executeRENAMEMATRIX");
    resetBlockStats();
    Matrix* matrix = matrixCatalogue.getMatrix(oldMat);
    matrix->rename(newMat);
    cout << "Total block count: " << matrix->blockCount << endl;    
    printBlockStats();
    resetBlockStats();
    return;
}