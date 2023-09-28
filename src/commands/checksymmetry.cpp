#include "global.h"

/**
 * @brief 
 * SYNTAX: CHECKSYMMETRY A
 */

// bool syntacticParseCHECKSYMMETRY(){
//     logger.log("syntacticParseCHECKSYMMETRY");
//     if (tokenizedQuery.size() != 2){
//         cout << "SYNTAX ERROR" << endl;
//         return false;
//     }
//     parsedQuery.queryType = CHECKSYMMETRY;
//     parsedQuery.checkSymmetryName = tokenizedQuery[1];
//     return true;
// }

bool semanticParseCHECKSYMMETRY(char* matrixName){
    string mat = matrixName;
    logger.log("semanticParseCHECKSYMMETRY");
    if (matrixCatalogue.isMatrix(mat))
        return true;
    cout << "SEMANTIC ERROR: No such matrix exists" << endl;
    return false;
}

void executeCHECKSYMMETRY(char* matrixName){
    string mat = matrixName;
    logger.log("executeCHECKSYMMETRY");
    resetBlockStats();
    Matrix* matrix = matrixCatalogue.getMatrix(mat);
    if(matrix->isSymmetric()) cout << "SYMMETRIC" << endl;
    else cout << "ASYMMETRIC" << endl;
    cout << "Total block count: " << matrix->blockCount << endl;
    printBlockStats();
    resetBlockStats();
    return;
}