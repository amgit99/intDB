#include "global.h"
/**
 * @brief 
 * SYNTAX: PRINT MATRIX A
 */
bool syntacticParsePRINTMATRIX(){
    logger.log("syntacticParsePRINTMATRIX");
    if (tokenizedQuery.size() != 3){
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType = PRINT_MATRIX;
    parsedQuery.printMatrixName = tokenizedQuery[2];
    return true;
}

bool semanticParsePRINTMATRIX(){
    logger.log("semanticParsePRINTMATRIX");
    logger.log("semanticParsePRINTMATRIX:: " + parsedQuery.printMatrixName);
    for(auto itr: matrixCatalogue.matrices) logger.log(itr.first);

    if (!matrixCatalogue.isMatrix(parsedQuery.printMatrixName)){
        cout << "SEMANTIC ERROR: Matrix doesn't exist" << endl;
        return false;
    }
    return true;
}

void executePRINTMATRIX(){
    logger.log("executePRINTMATRIX");
    Matrix *matrix = matrixCatalogue.getMatrix(parsedQuery.printMatrixName);
    matrix->print();
    return;
}
