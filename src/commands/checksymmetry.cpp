#include "global.h"

/**
 * @brief 
 * SYNTAX: CHECKSYMMETRY A
 */

bool syntacticParseCHECKSYMMETRY(){
    logger.log("syntacticParseCHECKSYMMETRY");
    if (tokenizedQuery.size() != 2){
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType = CHECKSYMMETRY;
    parsedQuery.checkSymmetryName = tokenizedQuery[1];
    return true;
}

bool semanticParseCHECKSYMMETRY(){
    logger.log("semanticParseCHECKSYMMETRY");
    if (matrixCatalogue.isMatrix(parsedQuery.checkSymmetryName))
        return true;
    cout << "SEMANTIC ERROR: No such matrix exists" << endl;
    return false;
}

void executeCHECKSYMMETRY(){
    logger.log("executeCHECKSYMMETRY");
    Matrix* matrix = matrixCatalogue.getMatrix(parsedQuery.checkSymmetryName);
    if(matrix->isSymmetric()) cout << "HAI BHAI" << endl;
    else cout << "NAHI HAI BHAI" << endl;
    return;
}