#include "mycursor.h"
#include "globals.h"

MyCursor::MyCursor(string tableName, int pageIndex){
    logger.log("MyCursor::MyCursor");
    this->tableName = tableName;
    Table* table = tableCatalogue.getTable(tableName);
    this->rowCount = table->rowCount;
    this->blockRowCount = table->maxRowsPerBlock;
    this->page = bufferManager.getPage(tableName, pageIndex);
    this->pageIndex = pageIndex;
    this->rowNumber = 0;
    this->rowOffset = 0;
    logger.log("LEFT MyCursor::MyCursor");
}

MyCursor::MyCursor(string tableName, long long rowIndex){
    this->tableName = tableName;
    Table* table = tableCatalogue.getTable(tableName);
    this->rowCount = table->rowCount;
    this->blockRowCount = table->maxRowsPerBlock;
    this->pageIndex = rowIndex/table->maxRowsPerBlock;
    this->page = bufferManager.getPage(tableName, this->pageIndex);
    this->rowNumber = rowIndex;
    this->rowOffset = rowIndex%table->maxRowsPerBlock;
}

vector<int> MyCursor::getRow(){
    logger.log("MyCursor::getRow");
    if(this->rowOffset==this->blockRowCount){
        int nextPageIndex = this->pageIndex+1;
        if(nextPageIndex == tableCatalogue.getTable(this->tableName)->blockCount){
            this->page = bufferManager.getPage(this->tableName, 0); // wrap around;
            this->rowOffset = this->pageIndex = this->rowNumber = 0;
        }
        else {
            this->page = bufferManager.getPage(this->tableName, this->pageIndex+1);
            this->rowOffset = 0;
            this->rowCount++;
            this->pageIndex++;
        }
    }
    else{
        this->rowCount++;
    }
    logger.log("LEFT MyCursor::getRow");
    return this->page.rows[this->rowOffset++];
}

