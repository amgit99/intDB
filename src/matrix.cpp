#include "global.h"

Matrix::Matrix(){
}

Matrix::Matrix(string matrixName){
    this->sourceFileName = "./data/" + matrixName + ".csv";
    this->matrixName = matrixName;
}

bool Matrix::load(){
    logger.log("Matrix::load"); 
    string line;
    ifstream fi(this->sourceFileName);
    getline(fi,line); 

    this->columnCount = 1;
    for(auto itr: line) if(itr==',') this->columnCount++;
    this->sliceSize = sqrt((BLOCK_SIZE * 1000) / sizeof(int));
    this->horizontalSliceCount = ceil((float)this->columnCount/this->sliceSize); 

    // INITIALISE THE OFFSETS VECTOR AND ADD ALL THE INITIAL OFFSETS ALONG WITH THEIR RUNNING SUM.
    // RUNNING SUM FOR SEEKG = PREV SUM + LINE CHAR COUNT + 1 FOR NEWLINE.

    vector<int> offsets = {0, (int)line.size()+1};
    while(getline(fi, line)) offsets.push_back(offsets.back()+line.size()+1); 
    this->rowCount = offsets.size()-1;
    this->verticalSliceCount = ceil((float)this->rowCount/this->sliceSize);
    this->blockCount = horizontalSliceCount*verticalSliceCount;

    fi.close();

    this->blockify(offsets);

    return true;
}

bool Matrix::blockify(vector<int> &offsets){
    logger.log("Matrix::blockify"); 
    this->writeOffsets.resize(this->rowCount+1, this->columnCount);
    this->rowsPerBlockCount.resize(this->blockCount, 0);
    this->colsPerBlockCount.resize(this->blockCount, 0);
    this->writeOffsets[0] = 0;
    
    // INITIALIZE VECTOR THAT WILL HOLD VALUES AND MAKE PAGES FROM THAT;
    vector<vector<int>> pageVector(this->sliceSize, vector<int>(this->sliceSize));
    ifstream file(this->sourceFileName);
    int currPageId;

    for(int i=0; i<this->verticalSliceCount; ++i){
        int lineNumber = i*this->sliceSize;
        for(int j=0; j<this->horizontalSliceCount; ++j){
            int wordNumber = j*this->sliceSize;
            int lineOffset, wordOffset;

            for(lineOffset=0; lineNumber+lineOffset<this->rowCount && lineOffset<this->sliceSize; ++lineOffset){
                int trueLine = lineNumber+lineOffset;
                wordOffset = 0;

                file.seekg(offsets[trueLine]);

                char ch; string number = "";
                int charCount = 0, digitCount = 0, numberCount = 0;
                while (file.get(ch)) {
                    if(ch==',' || ch=='\n'){
                        pageVector[lineOffset][wordOffset] = stoi(number);
                        ++wordOffset;
                        digitCount += number.size();
                        number = "";
                        if(wordOffset==this->sliceSize || ch=='\n') { ++charCount; break; }
                    }
                    else if(ch!=' ') number+=ch;
                    ++charCount;
                }
                offsets[trueLine]+=charCount;
                this->writeOffsets[trueLine+1] += digitCount;
            }
            currPageId = this->getPageId(i,j);
            this->rowsPerBlockCount[currPageId] = lineOffset;
            this->colsPerBlockCount[currPageId] = wordOffset;
            bufferManager.writePage(this->matrixName, lineOffset, wordOffset, pageVector, currPageId);
        }
    }
    for(int i=1; i<this->writeOffsets.size(); ++i) this->writeOffsets[i]+=this->writeOffsets[i-1];
    file.close();
    return 0;
}

void Matrix::print(){
    logger.log("Matrix::print");
    this->exportMatrix(min(this->rowCount, PRINT_COUNT), min(this->columnCount, PRINT_COUNT));
    string command = "cat "+this->sourceFileName;
    system(command.c_str());
    // string yeetTempFile = "rm -f ./data/" + this->matrixName + ".csv";
    // system(yeetTempFile.c_str());
}

void Matrix::makePermanent(){
}

bool Matrix::isPermanent(){
return false;
}

void Matrix::unload(){
}

// SUBSTITUTIONS :: 
//     GENERAL                EXPORT                          SUBSTITUTION
// horizontalSlices = this->horizontalSliceCount || ceil((float)PRINT_SIZE/sliceSize);
// verticalSlices   = this->verticalSliceCount   || ceil((float)BLOCK_SIZE/sliceSize);
// rowsToPrint      = this->rowCount             || rowsToPrint;
// colsToPrint      = currentPage.columnCount    || colsToPrint;

void Matrix::exportMatrix(int rowsToPrint, int colsToPrint){
    logger.log("Matrix::exportMatrix");

    string destName = "./data/" + this->matrixName + ".csv";
    ofstream outputFile(destName, std::ios::binary | std::ios::out);

    for(int i=0; i<this->verticalSliceCount; ++i){
        int lineNumber = i*this->sliceSize;
        for(int j=0; j<this->horizontalSliceCount; ++j){
            int wordNumber = j*this->sliceSize; 
            int lineOffset, wordOffset;

            logger.log("Matrix::exportMatrix 1");
            Page *currentPage;
            bufferManager.getPage(*this, this->getPageId(i,j), currentPage);
            logger.log("Matrix::exportMatrix 2");
            for(lineOffset=0; lineNumber+lineOffset<this->rowCount && lineOffset<this->sliceSize; ++lineOffset){
                int trueLine = lineNumber+lineOffset;
                
                string injectedRow = "";
                for(wordOffset=0; wordOffset+wordNumber<colsToPrint && wordOffset<this->sliceSize; ++wordOffset)
                    injectedRow += to_string(currentPage->rows[lineOffset][wordOffset])+',';

                if(j==this->horizontalSliceCount-1){
                    injectedRow.pop_back();
                    injectedRow+='\n';
                }
                // logger.log("injectedRow:: " + injectedRow);

                outputFile.seekp(this->writeOffsets[trueLine]);
                outputFile.write(injectedRow.c_str(), injectedRow.size());
                this->writeOffsets[trueLine] += injectedRow.size();
            }
            logger.log("Matrix::exportMatrix 3");
        }
    }
    outputFile.close();
}

int Matrix::getPageId(int x, int y){
    return x*this->horizontalSliceCount+y;
}

pair<int,int> Matrix::getGridDimentions(int pageId){
    return {pageId/this->columnCount, pageId%this->columnCount};
}

void Matrix::transpose(){   
    Page *A, *B;

    for(int i=0; i<this->verticalSliceCount; ++i){
        for(int j=0; j<=i; ++j){
            bufferManager.getPage(*this, this->getPageId(i, j), A);
            bufferManager.getPage(*this, this->getPageId(j, i), B);

            for(int ii=0; ii<A->rowCount; ++ii)
                for(int jj=0; jj<A->columnCount; ++jj)
                    swap(A->rows[ii][jj], B->rows[jj][ii]);
            
            bufferManager.writePage(this->matrixName, A->rowCount, A->columnCount, A->rows, this->getPageId(i, j));
            bufferManager.writePage(this->matrixName, B->rowCount, B->columnCount, B->rows, this->getPageId(j, i));
        }
    }
}

bool Matrix::isSymmetric(){   
    Page *A, *B;

    for(int i=0; i<this->verticalSliceCount; ++i){
        for(int j=0; j<=i; ++j){
            bufferManager.getPage(*this, this->getPageId(i, j), A);
            bufferManager.getPage(*this, this->getPageId(j, i), B);

            for(int ii=0; ii<A->rowCount; ++ii)
                for(int jj=0; jj<A->columnCount; ++jj)
                    if(A->rows[ii][jj] != B->rows[jj][ii])
                        return 0;
            
        }
    }
    return true;
}

void Matrix::compute(){   
    Page *A, *B;
    int temp;

    for(int i=0; i<this->verticalSliceCount; ++i){
        for(int j=0; j<=i; ++j){
            bufferManager.getPage(*this, this->getPageId(i, j), A);
            bufferManager.getPage(*this, this->getPageId(j, i), B);

            for(int ii=0; ii<A->rowCount; ++ii)
                for(int jj=0; jj<A->columnCount; ++jj){
                    temp = A->rows[ii][jj];
                    A->rows[ii][jj] = A->rows[ii][jj] - B->rows[jj][ii];
                    B->rows[jj][ii] = B->rows[jj][ii] - temp;
                }
            
            bufferManager.writePage(this->matrixName, A->rowCount, A->columnCount, A->rows, this->getPageId(i, j));
            bufferManager.writePage(this->matrixName, B->rowCount, B->columnCount, B->rows, this->getPageId(j, i));
        }
    }
}
