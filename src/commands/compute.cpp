#include "global.h"

/**
 * @brief 
 * SYNTAX: COMPUTE A
 */

// bool syntacticParseCOMPUTE(){
//     logger.log("syntacticParseCOMPUTE");
//     if (tokenizedQuery.size() != 2){
//         cout << "SYNTAX ERROR" << endl;
//         return false;
//     }
//     parsedQuery.queryType = COMPUTE;
//     parsedQuery.computeName = tokenizedQuery[1];
//     return true;
// }

bool semanticParseCOMPUTE(char* matrixName){
    string mat = matrixName;
    logger.log("semanticParseCOMPUTE");
    if (matrixCatalogue.isMatrix(mat))
        return true;
    cout << "SEMANTIC ERROR: No such matrix exists" << endl;
    return false;
}

void executeCOMPUTE(char* matrixName){
    string mat = matrixName;
    logger.log("executeCOMPUTE");
    resetBlockStats();

    Matrix* matrix = matrixCatalogue.getMatrix(mat);

    string originalMatrixName = mat;
    string originalSourceFileName = matrix->sourceFileName;

    // NOTE: "A" is placeholder used in the comments below that refers to the original matrix name

    // Export current matrix
    string salt = "OG_";
    string exportDest = "./data/exports/" + salt + originalMatrixName + ".csv";
    matrix->exportMatrix(matrix->rowCount, matrix->columnCount, salt);

    // Compute A - A^T on the renamed matrix (result is stored in the renamed matrix itself)
    matrix->compute();
        
    // Rename the computed A - A^T i. e. previously A, to A_RESULT
    matrix->rename(matrix->matrixName+"_RESULT");

    // Load the previously exported (original) matrix i. e. A
    Matrix *orig_matrix = new Matrix(salt + originalMatrixName);

    orig_matrix->sourceFileName = exportDest;
    if(orig_matrix->load()){
        cout << "Load Successful" << endl;
        matrixCatalogue.insertMatrix(orig_matrix);
    }
    else{
        cout << "Failed." << endl;
        return;
    }

    // Rename the matrix just loaded i. e. (effectively A), to its original name
    orig_matrix->rename(originalMatrixName);

    // Change sourceFileName of A (just renamed to A from temp_A) to its original sourceFileName
    orig_matrix->sourceFileName = originalSourceFileName;

    // Delete the exported file for the original matrix i. e. temp_A.csv
    system(string("rm -f " + exportDest).c_str());

    // Set matrix to origiginal matrix
    matrix = orig_matrix;

    cout << "Total block count: " << matrix->blockCount << endl;    
    printBlockStats();
    resetBlockStats();
    return;
}