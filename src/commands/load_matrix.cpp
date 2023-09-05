#include "global.h"
/**
 * @brief 
 * SYNTAX: LOAD MATRIX A
 */
bool syntacticParseLOADMATRIX(){
    logger.log("syntacticParseLOADMATRIX");
    if (tokenizedQuery.size() != 3){
        cout << "SYNTAX ERROR" << endl;
        return false;
    }
    parsedQuery.queryType= LOAD_MATRIX;
    parsedQuery.loadMatrixName = tokenizedQuery[2];
    return true;
}

bool semanticParseLOADMATRIX(){
    logger.log("semanticParseLOADMATRIX");
    if (matrixCatalogue.isMatrix(parsedQuery.loadMatrixName)){
        cout << "SEMANTIC ERROR: Matrix already exists" << endl;
        return false;
    }
    return true;
}

void executeLOADMATRIX(){
    logger.log("executeLOADMATRIX");

    Matrix *matrix = new Matrix(parsedQuery.loadMatrixName);
    if(matrix->load()){
        matrixCatalogue.insertMatrix(matrix);
        cout << "Loaded Matrix of Order: " << matrix->rowCount << endl;
    }
    return;
}