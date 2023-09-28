#include "global.h"
int offsets[10001];

Matrix::Matrix(){
}

Matrix::Matrix(string matrixName){
    string command = "mkdir ./data/temp/" + matrixName;
    system(command.c_str());
    this->sourceFileName = "./data/" + matrixName + ".csv";
    this->matrixName = matrixName;
}

bool Matrix::load(){

    stopwatch.lap();

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

    stopwatch.lap();

    this->blockify(offsets);

    stopwatch.lap();

    stopwatch.showSplits();

    return true;
}

bool Matrix::blockify(vector<int> &offsets){
    logger.log("Matrix::blockify"); 
    this->writeOffsets.resize(this->rowCount+1, this->columnCount);
    this->printOffsets.resize(min(this->columnCount, PRINT_COUNT)+1, 0);
    this->writeOffsets[0] = 0;
    this->printOffsets[0] = 0;
    this->rowsPerBlockCount.resize(this->blockCount, 0);
    this->colsPerBlockCount.resize(this->blockCount, 0);
    
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
                int charCount = 0, digitCount = 0;
                while (file.get(ch)){
                    if(ch==',' || ch=='\n'){
                        pageVector[lineOffset][wordOffset] = stoi(number);
                        ++wordOffset;
                        if(trueLine<=PRINT_COUNT && wordNumber+wordOffset<=PRINT_COUNT)
                            printOffsets[trueLine+1] += number.size()+1;
                        digitCount += number.length();
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
    for(int i=1; i<this->printOffsets.size(); ++i) this->printOffsets[i]+=this->printOffsets[i-1];
    for(int i=1; i<this->writeOffsets.size(); ++i) this->writeOffsets[i]+=this->writeOffsets[i-1];
    file.close();
    return 0;
}


// bool Matrix::load(){
//     auto t1 = std::chrono::high_resolution_clock::now();
//     int fd = open(this->sourceFileName.c_str(), O_RDONLY);
//     if (fd != -1) {
//         off_t fileLength = lseek(fd, 0, SEEK_END);
//         cout << "File Read of Size " << fileLength << " bytes" << endl;
//         char* fileData = (char*)mmap(nullptr, fileLength, PROT_READ, MAP_PRIVATE, fd, 0);
//         logger.log("MMAP complete");
//         if (fileData != MAP_FAILED) {

//             logger.log("MMAP successful");
//             this->columnCount = 1;
//             this->rowCount = 0;
//             long long  charCounter = 0;
//             while(fileData[charCounter]!='\n') {
//                 if(fileData[charCounter]==',') ++this->columnCount;
//                 ++charCounter;
//             } // This look calculates the number of columns based on the commas, 
//               // charCounter is now pointing to the address of the first \n.
            
//             logger.log("MMAP successful, col count :: "+to_string(this->columnCount));

//             while(charCounter < fileLength){
//                 if(fileData[charCounter]=='\n') {
//                     this->rowCount++;
//                     offsets[this->rowCount] = charCounter+1;
//                 }
//                 ++charCounter;
//             } // This calculates the offsets and the number of rows. 
            
//             logger.log("MMAP successful, row count :: "+to_string(this->rowCount));

//             this->sliceSize = sqrt((BLOCK_SIZE * 1000) / sizeof(int));
//             this->horizontalSliceCount = ceil((float)this->columnCount/this->sliceSize);
//             this->verticalSliceCount = ceil((float)this->rowCount/this->sliceSize);
//             this->blockCount = horizontalSliceCount*verticalSliceCount;

//             auto t2 = std::chrono::high_resolution_clock::now();

//             this->blockify(fileData, fileLength);

//             auto t3 = std::chrono::high_resolution_clock::now();
//             // auto interval1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
//             // auto interval2 = std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2);
//             std::chrono::duration<double, std::milli> interval1 = t2 - t1;
//             std::chrono::duration<double, std::milli> interval2 = t3 - t2;
//             cout << "INTERVAL 1 :: " << interval1.count() << "   INTERVAL 2 :: " << interval2.count() << endl;
//             munmap(fileData, fileLength);
//         }
//         close(fd);
//     }
//     return 1;
// }

// bool Matrix::blockify(char *fileData, int fileLength){
//     logger.log("Matrix::blockify"); 
//     this->writeOffsets.resize(this->rowCount+1, this->columnCount);
//     this->printOffsets.resize(min(this->columnCount, PRINT_COUNT)+1, 0);
//     this->writeOffsets[0] = 0;
//     this->rowsPerBlockCount.resize(this->blockCount, 0);
//     this->colsPerBlockCount.resize(this->blockCount, 0);
    
//     // INITIALIZE VECTOR THAT WILL HOLD VALUES AND MAKE PAGES FROM THAT;
//     vector<vector<int>> pageVector(this->sliceSize, vector<int>(this->sliceSize));
//     int currPageId, lineNumber, lineOffset, wordNumber, wordOffset, trueLine, currentChar, digitCount;
//     char ch; string number = "";

//     for(int i=0; i<this->verticalSliceCount; ++i){
//         lineNumber = i*this->sliceSize;
//         for(int j=0; j<this->horizontalSliceCount; ++j){
//             wordNumber = j*this->sliceSize;

//             for(lineOffset=0; lineNumber+lineOffset<this->rowCount && lineOffset<this->sliceSize; ++lineOffset){

//                 trueLine = lineNumber+lineOffset;
//                 wordOffset = 0;
//                 currentChar = offsets[trueLine]; // set the seek value acc to the block accessed.
//                 number = "";
//                 digitCount = 0;

//                 while(currentChar < fileLength){
//                     ch = fileData[currentChar++];
//                     if(ch==',' || ch=='\n'){
//                         pageVector[lineOffset][wordOffset] = stoi(number);
//                         ++wordOffset;
//                         if(trueLine<=PRINT_COUNT && wordNumber+wordOffset<=PRINT_COUNT)
//                             printOffsets[trueLine+1] += number.size()+1;
//                         digitCount += number.length();
//                         number = "";
//                         if(wordOffset==this->sliceSize || ch=='\n') break;
//                     }
//                     else if(ch!=' ') number+=ch;
//                 }
//                 offsets[trueLine]=currentChar;
//                 this->writeOffsets[trueLine+1] += digitCount;
//             }
//             currPageId = this->getPageId(i,j);
//             this->rowsPerBlockCount[currPageId] = lineOffset;
//             this->colsPerBlockCount[currPageId] = wordOffset;
//             bufferManager.writePage(this->matrixName, lineOffset, wordOffset, pageVector, currPageId);
//         }
//     }
//     for(int i=1; i<this->printOffsets.size(); ++i) this->printOffsets[i]+=this->printOffsets[i-1];
//     for(int i=1; i<this->writeOffsets.size(); ++i) this->writeOffsets[i]+=this->writeOffsets[i-1];
//     return 1;
//  }

void Matrix::print(){
    logger.log("Matrix::print");
    this->exportMatrix(min(this->rowCount, PRINT_COUNT), min(this->columnCount, PRINT_COUNT), "TEMP");
    string command = "cat ./data/exports/TEMP"+this->matrixName + ".csv";
    system(command.c_str());
    command = "rm -f ./data/exports/TEMP" + this->matrixName + ".csv";
    system(command.c_str());
}

void Matrix::makePermanent(){
}

bool Matrix::isPermanent(){
    return false;
}

void Matrix::unload(){
}

void Matrix::exportMatrix(int rowsToPrint, int colsToPrint, string salt){
    logger.log("Matrix::exportMatrix");

    int effectiveVerticalSliceCount = ceil((float)rowsToPrint/this->sliceSize);
    int effectiveHorizontalSliceCount = ceil((float)colsToPrint/this->sliceSize); 

    vector<uint> tempOffsets;

    if(salt=="TEMP") tempOffsets = this->printOffsets;
    else tempOffsets = this->writeOffsets;
    
    string destName = "./data/exports/" + salt + this->matrixName + ".csv";

    ofstream outputFile(destName);

    for(int i=0; i<effectiveVerticalSliceCount; ++i){
        int lineNumber = i*this->sliceSize;
        for(int j=0; j<effectiveHorizontalSliceCount; ++j){
            int wordNumber = j*this->sliceSize; 
            int lineOffset, wordOffset;

            Page *currentPage;
            bufferManager.getPage(*this, this->getPageId(i,j), currentPage);
            for(lineOffset=0; lineNumber+lineOffset<rowsToPrint && lineOffset<this->sliceSize; ++lineOffset){
                int trueLine = lineNumber+lineOffset;
                
                string injectedRow = "";
                for(wordOffset=0; wordOffset+wordNumber<colsToPrint && wordOffset<this->sliceSize; ++wordOffset)
                    injectedRow += to_string(currentPage->rows[lineOffset][wordOffset])+',';

                if(j==effectiveHorizontalSliceCount-1){
                    injectedRow.pop_back();
                    injectedRow+='\n';
                }

                outputFile.seekp(tempOffsets[trueLine]);
                outputFile.write(injectedRow.c_str(), injectedRow.size());
                tempOffsets[trueLine] += injectedRow.size();
            }
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

    vector<uint> newWriteOffsets(this->rowCount+1, 0), newPrintOffsets(min(this->rowCount, PRINT_COUNT)+1, 0);
    newWriteOffsets[0] = newPrintOffsets[0] = 0;

    logger.log("Matrix::transpose");
    for(int i=0; i<this->verticalSliceCount; ++i){
        for(int j=0; j<=i; ++j){
            bufferManager.getPage(*this, this->getPageId(i, j), A);
            if(i != j) bufferManager.getPage(*this, this->getPageId(j, i), B);
            else B=A;

            for(int ii=0; ii<A->rowCount; ++ii){
                for(int jj=0; jj<A->columnCount; ++jj){
                    if(i==j){
                        if(ii<jj) swap(A->rows[ii][jj], B->rows[jj][ii]);
                    }
                    else swap(A->rows[ii][jj], B->rows[jj][ii]);

                    if(i==j){
                        if(jj<ii){
                            newWriteOffsets[i*this->sliceSize+ii+1] += to_string(A->rows[ii][jj]).size()+1;
                            newWriteOffsets[j*this->sliceSize+jj+1] += to_string(A->rows[jj][ii]).size()+1;
                            if(i*this->sliceSize+ii < PRINT_COUNT){
                                newPrintOffsets[i*this->sliceSize+ii+1] += to_string(A->rows[ii][jj]).size()+1;
                                newPrintOffsets[j*this->sliceSize+jj+1] += to_string(A->rows[jj][ii]).size()+1;
                            }
                        }
                        else if(ii==jj){
                            newWriteOffsets[j*this->sliceSize+jj+1] += to_string(A->rows[jj][ii]).size()+1;
                            if(j*this->sliceSize+jj < PRINT_COUNT){
                                newPrintOffsets[j*this->sliceSize+jj+1] += to_string(A->rows[jj][ii]).size()+1;
                            }
                        }
                    }
                    else {
                        newWriteOffsets[i*this->sliceSize+ii+1] += to_string(A->rows[ii][jj]).size()+1;
                        newWriteOffsets[j*this->sliceSize+jj+1] += to_string(B->rows[jj][ii]).size()+1;
                        if(i*this->sliceSize+ii < PRINT_COUNT){
                            newPrintOffsets[i*this->sliceSize+ii+1] += to_string(A->rows[ii][jj]).size()+1;
                            newPrintOffsets[j*this->sliceSize+jj+1] += to_string(B->rows[jj][ii]).size()+1;
                        }
                    }
                }
            }
            bufferManager.writePage(this->matrixName, A->rowCount, A->columnCount, A->rows, this->getPageId(i, j));
            if(i != j) bufferManager.writePage(this->matrixName, B->rowCount, B->columnCount, B->rows, this->getPageId(j, i));
        }
    }
    this->writeOffsets = newWriteOffsets;
    this->printOffsets = newPrintOffsets;
    for(int i=1; i<writeOffsets.size(); ++i) this->writeOffsets[i] += this->writeOffsets[i-1];
    for(int i=1; i<printOffsets.size(); ++i) this->printOffsets[i] += this->printOffsets[i-1];
}

bool Matrix::isSymmetric(){
    Page *A, *B;

    logger.log("Matrix::isSymmetric");
    for (int i = 0; i < this->verticalSliceCount; ++i){
        for (int j = 0; j <= i; ++j){
            bufferManager.getPage(*this, this->getPageId(i, j), A);
            if (i != j)
                bufferManager.getPage(*this, this->getPageId(j, i), B);
            else
                B = A;

            for (int ii = 0; ii < A->rowCount; ++ii){
                for (int jj = 0; jj < A->columnCount; ++jj){
                    if (A->rows[ii][jj] != B->rows[jj][ii]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void Matrix::compute(){
    Page *A, *B;
    int temp;

    logger.log("Matrix::compute");
    vector<uint> newWriteOffsets(this->rowCount+1, 0), newPrintOffsets(min(this->rowCount, PRINT_COUNT)+1, 0);
    newWriteOffsets[0] = newPrintOffsets[0] = 0;

    for (int i = 0; i < this->verticalSliceCount; ++i){
        for (int j = 0; j <= i; ++j){
            bufferManager.getPage(*this, this->getPageId(i, j), A);
            if (i != j)
                bufferManager.getPage(*this, this->getPageId(j, i), B);
            else
                B = A;

            for (int ii = 0; ii < A->rowCount; ++ii){
                for (int jj = 0; jj < A->columnCount; ++jj){

                    if(i==j){
                        if(ii<jj) {
                            temp = A->rows[ii][jj];
                            A->rows[ii][jj] -= B->rows[jj][ii];
                            B->rows[jj][ii] -= temp;
                        }
                        else if(ii==jj) A->rows[ii][jj] = 0;
                    }
                    else{
                        temp = A->rows[ii][jj];
                        A->rows[ii][jj] = A->rows[ii][jj] - B->rows[jj][ii];
                        B->rows[jj][ii] = B->rows[jj][ii] - temp;
                    }

                    if(i==j){
                        if(jj<ii){
                            newWriteOffsets[i*this->sliceSize+ii+1] += to_string(A->rows[ii][jj]).size()+1;
                            newWriteOffsets[j*this->sliceSize+jj+1] += to_string(A->rows[jj][ii]).size()+1;
                            if(i*this->sliceSize+ii < PRINT_COUNT){
                                newPrintOffsets[i*this->sliceSize+ii+1] += to_string(A->rows[ii][jj]).size()+1;
                                newPrintOffsets[j*this->sliceSize+jj+1] += to_string(A->rows[jj][ii]).size()+1;
                            }
                        }
                        else if(ii==jj){
                            newWriteOffsets[j*this->sliceSize+jj+1] += to_string(A->rows[jj][ii]).size()+1;
                            if(j*this->sliceSize+jj < PRINT_COUNT){
                                newPrintOffsets[j*this->sliceSize+jj+1] += to_string(A->rows[jj][ii]).size()+1;
                            }
                        }
                    }
                    else {
                        newWriteOffsets[i*this->sliceSize+ii+1] += to_string(A->rows[ii][jj]).size()+1;
                        newWriteOffsets[j*this->sliceSize+jj+1] += to_string(B->rows[jj][ii]).size()+1;
                        if(i*this->sliceSize+ii < PRINT_COUNT){
                            newPrintOffsets[i*this->sliceSize+ii+1] += to_string(A->rows[ii][jj]).size()+1;
                            newPrintOffsets[j*this->sliceSize+jj+1] += to_string(B->rows[jj][ii]).size()+1;
                        }
                    }
                }
            }
            bufferManager.writePage(this->matrixName, A->rowCount, A->columnCount, A->rows, this->getPageId(i, j));
            if(i != j) bufferManager.writePage(this->matrixName, B->rowCount, B->columnCount, B->rows, this->getPageId(j, i));
        }
    }
    this->writeOffsets = newWriteOffsets;
    this->printOffsets = newPrintOffsets;
    for(int i=1; i<writeOffsets.size(); ++i) this->writeOffsets[i] += this->writeOffsets[i-1];
    for(int i=1; i<printOffsets.size(); ++i) this->printOffsets[i] += this->printOffsets[i-1];
}

void Matrix::rename(string newName){
    logger.log("Matrix::rename");
    /// catalogue 
    matrixCatalogue.matrices.erase(this->matrixName);
    matrixCatalogue.matrices[newName] = this;
    /// command 
    string command = "mv ./data/temp/" + this->matrixName + " ./data/temp/" + newName;
    system(command.c_str());
    /// change map
    for(auto &itr: bufferManager.pages){
        string path = "./data/temp/" + this->matrixName + "/_Page" + itr.pageIndex;
        if(itr.pageName == path) 
            itr.pageName = "./data/temp/" + newName + "/_Page" + itr.pageIndex;
    }
    /// rename mat object
    this->matrixName = newName;
}