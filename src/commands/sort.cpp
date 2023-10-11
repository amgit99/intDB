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

bool Sort::updateArgList(string columnName, bool order){
    string column = columnName;
    logger.log("semanticParseSORT");

    if(!tableCatalogue.isTable(tableStack.top())){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }
    if(!tableCatalogue.isColumnFromTable(column, tableStack.top())){
        cout<<"SEMANTIC ERROR: Column doesn't exist in relation"<<endl;
        return false;
    }

    this->columnList.push_back(column);
    this->columnOrderList.push_back(order);
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

int Sort::merge(long long setSize, int stack1, int stack2){
    string effectiveName = "SORTED"+this->table->tableName;
    
    logger.log("Sort::merge");
    MyCursor cursorL = MyCursor(effectiveName, stack1);
    MyCursor cursorR = MyCursor(effectiveName, stack2);

    long long countL = this->table->maxRowsPerBlock*setSize;
    long long countR = min(2*countL, this->table->rowCount) - countL;

    vector<vector<int>> sortedVec;
    vector<int> topL = cursorL.getRow(), topR = cursorR.getRow();
    int writeIndex = stack1;

    // Merge from both sides till any one of them is empty
    while(countL > 0 && countR > 0){
        if(customSortFunction(topL, topR)){
            sortedVec.push_back(topL);
            --countL;
            if(countL > 0) topL = cursorL.getRow();
        } else {
            sortedVec.push_back(topR);
            --countR;
            if(countR > 0) topR = cursorR.getRow();
        }
        if(sortedVec.size()==this->table->maxRowsPerBlock){
            bufferManager.writePage("temp"+effectiveName, writeIndex++, sortedVec, sortedVec.size());
            sortedVec = {};
        }
    }
    // Merge the remaining left side
    while(countL > 0){
        sortedVec.push_back(topL);
        --countL;
        if(countL > 0) topL = cursorL.getRow();
        if(sortedVec.size()==this->table->maxRowsPerBlock){
            bufferManager.writePage("temp"+effectiveName, writeIndex++, sortedVec, sortedVec.size());
            sortedVec = {};
        }
    }
    // Merge the remaining right side
    while(countR > 0){
        sortedVec.push_back(topR);
        --countR;
        if(countR > 0) topR = cursorR.getRow();
        if(sortedVec.size()==this->table->maxRowsPerBlock){
            bufferManager.writePage("temp"+effectiveName, writeIndex++, sortedVec, sortedVec.size());
            sortedVec = {};
        }
    }
    // Write the last unwritten page
    if(sortedVec.size() > 1){
        bufferManager.writePage("temp"+effectiveName, writeIndex++, sortedVec, sortedVec.size());
        sortedVec = {};
    }
    return writeIndex;
}

bool Sort::execute(bool makeCopy){
    logger.log("Sort::executeSORT");
    reverse(columnList.begin(), columnList.end());
    // logger.log(tableStack.size());
    
    this->tableName = tableStack.top();
    tableStack.pop();
    table = tableCatalogue.getTable(this->tableName);
    for(int i=0; i<columnList.size(); ++i)
        sortConstraints.push_back({ table->getColumnIndex(columnList[i]),
                                    columnOrderList[i] });
    logger.log("Sort::sortConstraints updated");

    Table *sortedTable = new Table("SORTED"+this->table->tableName, this->table);
    tableCatalogue.insertTable(sortedTable);

    Page* page;
    for(int i=table->blockCount-1; i>=0; --i){
        bufferManager.getPage(table->tableName, i, page);
        logger.log("page loaded"+to_string(i));

        auto end = page->rows.begin();
        end += page->rowCount;

        std::sort(page->rows.begin(), end, customSortFunction);
        bufferManager.writePage("SORTED"+table->tableName, i, page->rows, page->rowCount);
    }

    int level = 1, renamed;
    while(level < table->blockCount){
        for(int i=0; i+level < table->blockCount; i+=2*level) 
            renamed = merge(level, i, i+level);
            cout << "RENAMED :: " << renamed << endl;
        for(int i=0; i<renamed; ++i){
            string ofn = "tempSORTED"+this->table->tableName+"_Page"+to_string(i);
            string nfn = "SORTED"+this->table->tableName+"_Page"+to_string(i);
            ofn = "data/temp/"+ofn; nfn = "data/temp/"+nfn;
            string command = "mv -f "+ofn+" "+nfn;
            system(command.c_str());
        }
        level *= 2;
    }

    if(makeCopy==0){
        for(int i=0; i<table->blockCount; ++i){
            string ofn = "SORTED"+this->table->tableName+"_Page"+to_string(i);
            string nfn = this->table->tableName+"_Page"+to_string(i);
            ofn = "data/temp/"+ofn; nfn = "data/temp/"+nfn;
            string command = "mv -f "+ofn+" "+nfn;
            system(command.c_str());
        }
        delete tableCatalogue.tables["SORTED"+tableName];
        tableCatalogue.tables.erase("SORTED"+this->tableName);
    }
    else tableStack.push("SORTED"+this->table->tableName);

    logger.log("Sort::LEFT executeSORT");
    return 0;
}

void Sort::clear(){
    this->sortConstraints.clear();
    this->columnList.clear();
    this->columnOrderList.clear();
}