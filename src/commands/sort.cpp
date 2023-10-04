#include "globals.h"
#include "sort.h"

/**
 * @brief File contains method to process SORT commands.
 * 
 * syntax:
 * R <- SORT relation_name BY column_name IN sorting_order
 * 
 * sorting_order = ASC | DESC 
 */

bool Sort::updateArgList(char* columnName, bool order){
    string column = columnName;
    logger.log("semanticParseSORT");

    if(!tableCatalogue.isTable(evaluatedTable.top())){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }
    if(!tableCatalogue.isColumnFromTable(column, evaluatedTable.top())){
        cout<<"SEMANTIC ERROR: Column doesn't exist in relation"<<endl;
        return false;
    }

    columnList.push_back(column);
    columnOrderList.push_back(order);

    return 0;
}

static bool customSortFunction(vector<int> &line1, vector<int> &line2){
    for(int i=0; i<sortQuery.sortConstraints.size(); ++i){
        int ind = sortQuery.sortConstraints[i].first;
        if(line1[ind]!=line2[ind]) {
            if(sortQuery.sortConstraints[i].second)
                return line1[ind] > line2[ind];
            else
                return line1[ind] < line2[ind];
        }
    }
    return 0;
}

void Sort::merge(long long setSize, int stack1, int stack2){
    logger.log("Sort::merge");
    MyCursor cursorL = MyCursor(this->table->tableName, stack1);
    MyCursor cursorR = MyCursor(this->table->tableName, stack2);

    long long countL = this->table->maxRowsPerBlock*setSize;
    long long countR = min(2*countL, this->table->rowCount) - countL;

    vector<vector<int>> sortedVec;
    vector<int> topL = cursorL.getRow(), topR = cursorR.getRow();
    int writeIndex = stack1;
    while(countL > 0 && countR > 0){
        if(customSortFunction(topL, topR)){
            sortedVec.push_back(topL);
            topL = cursorL.getRow();
            --countL;
        } else {
            sortedVec.push_back(topR);
            topR = cursorR.getRow();
            --countR;
        }
        if(sortedVec.size()==this->table->maxRowsPerBlock){
            bufferManager.writePage(this->table->tableName, writeIndex++, sortedVec, sortedVec.size());
            sortedVec = {};
        }
    }
    if(countL > 0){
        sortedVec.push_back(topL);
        topL = cursorL.getRow();
        --countL;
        if(sortedVec.size()==this->table->maxRowsPerBlock){
            bufferManager.writePage(this->table->tableName, writeIndex++, sortedVec, sortedVec.size());
            sortedVec = {};
        }
    }
    if(countR > 0){
        sortedVec.push_back(topR);
        topR = cursorR.getRow();
        --countR;
        if(sortedVec.size()==this->table->maxRowsPerBlock){
            bufferManager.writePage(this->table->tableName, writeIndex++, sortedVec, sortedVec.size());
            sortedVec = {};
        }
    }
    if(sortedVec.size() > 1){
        bufferManager.writePage(this->table->tableName, writeIndex++, sortedVec, sortedVec.size());
        sortedVec = {};
    }
}

bool Sort::execute(){
    logger.log("Sort::executeSORT");
    reverse(columnList.begin(), columnList.end());

    table = tableCatalogue.getTable(evaluatedTable.top());
    for(int i=0; i<columnList.size(); ++i)
        sortConstraints.push_back({ table->getColumnIndex(columnList[i]),
                                    columnOrderList[i] });
    logger.log("Sort::sortConstraints updated");

    Page* page;
    for(int i=table->blockCount-1; i>=0; --i){
        bufferManager.getPage(table->tableName, i, page);
        logger.log("page loaded"+to_string(i));

        auto end = page->rows.begin();
        end += page->rowCount;

        std::sort(page->rows.begin(), end, customSortFunction);
        bufferManager.writePage(table->tableName, i, page->rows, page->rowCount);
    }

    int level = 1;
    while(level <= table->blockCount){
        for(int i=0; i+level < table->blockCount; i+=2*level) 
            merge(level, i, i+level);
        level *= 2;
    }

    sortConstraints.clear();
    evaluatedTable.pop();
    columnList.clear();
    columnOrderList.clear();

    return 0;
}