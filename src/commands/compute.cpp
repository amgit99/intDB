#include "global.h"

/**
 * @brief 
 * SYNTAX: COMPUTE A
 */

bool syntacticParseCOMPUTE(){
    logger.log("syntacticParseCOMPUTE");
    if (tokenizedQuery.size() != 2){
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType = COMPUTE;
    parsedQuery.computeName = tokenizedQuery[1];
    return true;
}

bool semanticParseCOMPUTE(){
    logger.log("semanticParseCOMPUTE");
    if (matrixCatalogue.isMatrix(parsedQuery.computeName))
        return true;
    cout << "SEMANTIC ERROR: No such matrix exists" << endl;
    return false;
}

void executeCOMPUTE(){
    logger.log("executeCOMPUTE");
    Matrix* matrix = matrixCatalogue.getMatrix(parsedQuery.computeName);
    matrix->compute();
    return;
}