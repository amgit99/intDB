#include "global.h"
/**
 * @brief 
 * SYNTAX: PRINT MATRIX A
 */
// bool syntacticParsePRINTMATRIX(){
//     logger.log("syntacticParsePRINTMATRIX");
//     if (tokenizedQuery.size() != 3){
//         cout << "SYNTAX ERROR" << endl;
//         return false;
//     }
//     parsedQuery.queryType = PRINT_MATRIX;
//     parsedQuery.printMatrixName = tokenizedQuery[2];
//     return true;
// }

bool semanticParsePRINTMATRIX(char* matrixName){
    string mat = matrixName;
    logger.log("semanticParsePRINTMATRIX:: " + mat);
    for(auto itr: matrixCatalogue.matrices) logger.log(itr.first);

    if (!matrixCatalogue.isMatrix(mat)){
        cout << "SEMANTIC ERROR: Matrix doesn't exist" << endl;
        return false;
    }
    return true;
}

void executePRINTMATRIX(char* matrixName){
    string mat = matrixName;
    logger.log("executePRINTMATRIX");
    resetBlockStats();
    Matrix *matrix = matrixCatalogue.getMatrix(mat);
    matrix->print();
    cout << endl;
    cout << "Total block count: " << matrix->blockCount << endl;    
    printBlockStats();
    resetBlockStats();
    return;
}
