#include <iostream>
#include <bits/stdc++.h>
#include <sys/stat.h> 
#include <fstream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;
/**
 * @brief The Matrix class holds all information related to a loaded matrix. It
 * also implements methods that interact with the parsers, executors, cursors
 * and the buffer manager. A matrix object gets created through the
 * LOAD command
 */
class Matrix{

public:
    string sourceFileName;
    string matrixName;
    uint columnCount = 0;
    uint rowCount = 0;
    uint blockCount = 0;
    uint sliceSize = 0; // max no. of rows/cols of the matrix slice to be present in each block
    uint horizontalSliceCount;
    uint verticalSliceCount;
    vector<uint> rowsPerBlockCount;
    vector<uint> colsPerBlockCount;
    vector<uint> rowLength; // sum of byte length of all data items in a row of the matrix (is a stats Attribute)
    vector<uint> writeOffsets;
    vector<uint> printOffsets; 

    Matrix();
    Matrix(string matrixName);
    bool load();
    bool blockify(vector<int> &offsets);
    // bool load();
    // bool blockify(char *fileData, int fileLength);
    void print();
    void makePermanent();
    bool isPermanent();
    void unload();
    void exportMatrix(int rowsToPrint, int colsToPrint, string salt = "");
    int getPageId(int x, int y);
    pair<int,int> getGridDimentions(int pageId);
    void transpose();
    bool isSymmetric();
    void compute();
    void rename(string newName);
};