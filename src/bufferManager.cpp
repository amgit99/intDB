#include "globals.h"

BufferManager::BufferManager(){
    logger.log("BufferManager::BufferManager");
}

/**
 * @brief Function called to read a page from the buffer manager. If the page is
 * not present in the pool, the page is read and then inserted into the pool.
 *
 * @param tableName 
 * @param pageIndex 
 * @return Page 
 */
Page BufferManager::getPage(string tableName, int pageIndex){
    logger.log("BufferManager::getPage");
    string pageName = "./data/temp/" + tableName + "_Page" + to_string(pageIndex);
    if (this->inPool(pageName)){
        logger.log("BufferManager::Left getPage");
        return this->getFromPool(pageName);
    }
    else {
        logger.log("BufferManager::Left getPage");
        return this->insertIntoPool(tableName, pageIndex);
    }
}

void BufferManager::getPage(string tableName, int pageIndex, Page* &hook){
    logger.log("BufferManager::getPage");
    string pageName = "./data/temp/" + tableName + "_Page" + to_string(pageIndex);
    if (this->inPool(pageName)){
        
        this->getFromPool(pageName, hook);
    }
    else {
        this->insertIntoPool(tableName, pageIndex, hook);
    }
    logger.log("BufferManager::Left getPage");
}

void BufferManager::getPage(Matrix &matrix, int pageIndex, Page* &hook){
    logger.log("BufferManager(matrix)::getPage");
    string pageName = "./data/temp/" + matrix.matrixName + "/_Page" + to_string(pageIndex);
    if (this->inPool(pageName))
        this->getFromPool(pageName, hook);
    else{
        this->insertIntoPool(matrix, pageIndex, hook);
    }
}

/**
 * @brief Checks to see if a page exists in the pool
 *
 * @param pageName 
 * @return true 
 * @return false 
 */
bool BufferManager::inPool(string pageName){
    logger.log("BufferManager::inPool");
    for (auto page : this->pages){
        if (pageName == page.pageName){
            logger.log("BufferManager::Left inPool");
            return true;
        }
    }
    logger.log("BufferManager::Left inPool");
    return false;
}

/**
 * @brief If the page is present in the pool, then this function returns the
 * page. Note that this function will fail if the page is not present in the
 * pool.
 *
 * @param pageName 
 * @return Page 
 */
Page BufferManager::getFromPool(string pageName){
    logger.log("BufferManager::getFromPool");
    for (auto page : this->pages)
        if (pageName == page.pageName)
            return page;
    return this->pages.front();
}
void BufferManager::getFromPool(string pageName, Page* &hook){
    logger.log("BufferManager(matrix)::getFromPool");
    for (auto& page : this->pages){
        if (pageName == page.pageName){
            hook = &page;
            return;
        }
    }
    logger.log("BufferManager(matrix)::getFromPool: Not found in pool");
}

/**
 * @brief Inserts page indicated by tableName and pageIndex into pool. If the
 * pool is full, the pool ejects the oldest inserted page from the pool and adds
 * the current page at the end. It naturally follows a queue data structure. 
 *
 * @param tableName 
 * @param pageIndex 
 * @return Page 
 */
void BufferManager::insertIntoPool(string tableName, int pageIndex, Page* &hook){
    logger.log("BufferManager(table)::insertIntoPool");
    Page* tempPage = new Page(tableName, pageIndex);
    if (this->pages.size() >= BLOCK_COUNT)
        pages.pop_front();
    pages.push_back(*tempPage);
    BLOCKS_READ++;
    hook = &pages.back();
    delete tempPage;
}

Page BufferManager::insertIntoPool(string tableName, int pageIndex){
    logger.log("BufferManager::insertIntoPool");
    Page page(tableName, pageIndex);
    if (this->pages.size() >= BLOCK_COUNT)
        pages.pop_front();
    pages.push_back(page);
    logger.log("Page::Left insertIntoPool");
    return page;
}

void BufferManager::insertIntoPool(Matrix &matrix, int pageIndex, Page* &hook){
    logger.log("BufferManager(matrix)::insertIntoPool");
    Page* tempPage = new Page(matrix, pageIndex);
    if (this->pages.size() >= BLOCK_COUNT)
        pages.pop_front();
    pages.push_back(*tempPage);
    BLOCKS_READ++;
    hook = &pages.back();
    delete tempPage;
}


/**
 * @brief The buffer manager is also responsible for writing pages. This is
 * called when new tables are created using assignment statements.
 *
 * @param tableName 
 * @param pageIndex 
 * @param rows 
 * @param rowCount 
 */
void BufferManager::writePage(string tableName, int pageIndex, vector<vector<int>> rows, int rowCount){
    logger.log("BufferManager::writePage");
    Page page(tableName, pageIndex, rows, rowCount);
    page.writePage();
}
/**
 * @brief Writes a Matrix page
 *
 * @param matrix
 * @param rowCount
 * @param colCount
 * @param data
 * @param pageIndex
 */
void BufferManager::writePage(string matrixName, int rowCount, int colCount, vector<vector<int>> &data, int pageIndex){
    logger.log("BufferManager::writePage");
    Page page(matrixName, rowCount, colCount, data, pageIndex);
    page.writePage();
    BLOCKS_WRITTEN++;
}

/**
 * @brief Deletes file names fileName
 *
 * @param fileName 
 */
void BufferManager::deleteFile(string fileName){
    if (remove(fileName.c_str()))
        logger.log("BufferManager::deleteFile: Err");
        else logger.log("BufferManager::deleteFile: Success");
}

/**
 * @brief Overloaded function that calls deleteFile(fileName) by constructing
 * the fileName from the tableName and pageIndex.
 *
 * @param tableName 
 * @param pageIndex 
 */
void BufferManager::deleteFile(string tableName, int pageIndex){
    logger.log("BufferManager::deleteFile");
    string fileName = "./data/temp/"+tableName + "_Page" + to_string(pageIndex);
    this->deleteFile(fileName);
}