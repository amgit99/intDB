#include "globals.h"

void MatrixCatalogue::insertMatrix(Matrix* matrix){
    logger.log("MatrixCatalogue::~insertMatrix");
    // cout << "Inserted Matrix :: " << matrix->matrixName << endl;
    this->matrices[matrix->matrixName] = matrix;
}

void MatrixCatalogue::deleteMatrix(string matrixName){
    logger.log("MatrixCatalogue::deleteMatrix"); 
    this->matrices[matrixName]->unload();
    delete this->matrices[matrixName];
    this->matrices.erase(matrixName);
}

Matrix* MatrixCatalogue::getMatrix(string matrixName){
    logger.log("MatrixCatalogue::getMatrix"); 
    // cout << "MatrixCatalogue::getMatrix::matrixName " << matrixName << endl;
    Matrix *matrix = this->matrices[matrixName];
    return matrix;
}

bool MatrixCatalogue::isMatrix(string matrixName){
    logger.log("MatrixCatalogue::isMatrix"); 
    // cout << "MatrixCatalogue::isMatrix::matrixName::" << matrixName << endl;
    if (this->matrices.count(matrixName))
        return true;
    return false;
}

void MatrixCatalogue::print(){
    logger.log("MatrixCatalogue::print"); 
    cout << "\nRELATIONS" << endl;

    int rowCount = 0;
    for (auto rel : this->matrices){
        cout << rel.first << endl;
        rowCount++;
    }
    cout << "\n\nRow Count: " << rowCount << endl;
}

MatrixCatalogue::~MatrixCatalogue(){
    logger.log("MatrixCatalogue::~MatrixCatalogue"); 
    for(auto matrix: this->matrices){
        matrix.second->unload();
        delete matrix.second;
    }
}
