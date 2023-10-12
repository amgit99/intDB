#include "globals.h"
#include "matrix.h"
#include "semanticParser.h"
/**
 * @brief 
 * SYNTAX: LOAD MATRIX A
 */

bool semanticParseLOADMATRIX(char* matrixName){
    logger.log("semanticParseLOADMATRIX");
    string mat = matrixName;
    if (matrixCatalogue.isMatrix(mat)){
        cout << "SEMANTIC ERROR: Matrix already exists" << endl;
        return false;
    }
    if (!fileExists(mat)){
        cout << "SEMANTIC ERROR: Data file doesn't exist" << endl;
        return false;
    }
    return true;
}

void executeLOADMATRIX(char* matrixName){
    logger.log("executeLOADMATRIX");
    string mat = matrixName;
    resetBlockStats();

    Matrix *matrix = new Matrix(mat);
    if(matrix->load()){
        matrixCatalogue.insertMatrix(matrix);
        cout << "Loaded Matrix of Order: " << matrix->rowCount << endl;
        cout << "Total block count: " << matrix->blockCount << endl;
        printBlockStats();
    }
    else{
        cout << "Failed to load Matrix" << endl;
    }
    resetBlockStats();
    return;
}