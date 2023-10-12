#include "globals.h"
#include "base.h"
#include "group.h"

int Group::getStat(int colId, int fnId){
    switch (fnId) {
        case 1: return this->stats[colId].min_;
        case 2: return this->stats[colId].max_;
        case 3: return this->stats[colId].sum_;
        case 4: return this->stats[colId].count_;
        case 5: return this->stats[colId].sum_/this->stats[colId].count_;
        default: return -1;
    }
}

bool Group::checkCondition(int conditionValue){
    switch (this->op) {
        case 1: return conditionValue >  this->conditionFiledValue;
        case 2: return conditionValue <  this->conditionFiledValue;
        case 3: return conditionValue == this->conditionFiledValue;
        case 4: return conditionValue != this->conditionFiledValue;
        case 5: return conditionValue <= this->conditionFiledValue;
        case 6: return conditionValue >= this->conditionFiledValue;
        default: return false;
    }
}

bool Group::updateStats(vector<int> &row){
    if(currentGroupingFieldValue!=row[groupingColumnId]){
        this->newRow = {currentGroupingFieldValue, this->getStat(this->returnColumnId, this->returnFunction)};
        int conditionValue = this->getStat(this->conditionColumnId, this->conditionFunction);
        currentGroupingFieldValue = row[groupingColumnId];

        this->stats[this->conditionColumnId].min_ = row[this->conditionColumnId];
        this->stats[this->conditionColumnId].max_ = row[this->conditionColumnId];
        this->stats[this->conditionColumnId].sum_ = row[this->conditionColumnId];
        this->stats[this->conditionColumnId].count_ = 1;

        this->stats[this->returnColumnId].min_ = row[this->returnColumnId];
        this->stats[this->returnColumnId].max_ = row[this->returnColumnId];
        this->stats[this->returnColumnId].sum_ = row[this->returnColumnId];
        this->stats[this->returnColumnId].count_ = 1;

        if(this->checkCondition(conditionValue)) return true;
        else return false;

    } else {
        this->stats[this->conditionColumnId].min_   = min(this->stats[this->conditionColumnId].min_, row[this->conditionColumnId]);
        this->stats[this->conditionColumnId].max_   = max(this->stats[this->conditionColumnId].max_, row[this->conditionColumnId]);
        this->stats[this->conditionColumnId].sum_   += row[this->conditionColumnId];
        this->stats[this->conditionColumnId].count_ += 1;

        if(this->conditionColumnId != this->returnColumnId) {
            this->stats[this->returnColumnId].min_   = min(this->stats[this->returnColumnId].min_, row[this->returnColumnId]);
            this->stats[this->returnColumnId].max_   = max(this->stats[this->returnColumnId].max_, row[this->returnColumnId]);
            this->stats[this->returnColumnId].sum_   += row[this->returnColumnId];
            this->stats[this->returnColumnId].count_ += 1;
        }

        return false;
    }
}

bool Group::checkArgs(){
    // VERIFY TABLE
    this->tableName = tableStack.top();
    tableStack.pop();
    if(!tableCatalogue.isTable(this->tableName)){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }

    // VERIFY GROUPING COLUMN
    this->groupingColumn = columnStack.top();
    columnStack.pop();
    if(!tableCatalogue.isColumnFromTable(this->groupingColumn, this->tableName)){
        cout<<"SEMANTIC ERROR: Column "<< this->groupingColumn <<" doesn't exist in relation " << this->tableName <<endl;
        return false;
    }
    this->groupingColumnId = tableCatalogue.getTable(this->tableName)->getColumnIndex(this->groupingColumn);

    // VERIFY RETURN COLUMN
    this->returnColumn = aggregateFunctionStack.top().second;
    this->returnFunction = aggregateFunctionStack.top().first;
    aggregateFunctionStack.pop();
    if(!tableCatalogue.isColumnFromTable(this->returnColumn, this->tableName)){
        cout<<"SEMANTIC ERROR: Column "<< this->returnColumn <<" doesn't exist in relation " << this->tableName <<endl;
        return false;
    }
    this->returnColumnId = tableCatalogue.getTable(this->tableName)->getColumnIndex(this->returnColumn);

    // VERIFY CONDITION COLUMN
    this->conditionColumn = aggregateFunctionStack.top().second;
    this->conditionFunction = aggregateFunctionStack.top().first;
    aggregateFunctionStack.pop();
    if(!tableCatalogue.isColumnFromTable(this->conditionColumn, this->tableName)){
        cout<<"SEMANTIC ERROR: Column "<< this->conditionColumn <<" doesn't exist in relation " << this->tableName <<endl;
        return false;
    }
    this->conditionColumnId = tableCatalogue.getTable(this->tableName)->getColumnIndex(this->conditionColumn);

    // UPDATE OPERANDS
    this->conditionFiledValue = intOperandStack.top();
    intOperandStack.pop();
    string opstr = operationStack.top();
    if (opstr==">" ) this->op = 1;
    else if (opstr=="<" ) this->op = 2;
    else if (opstr=="==") this->op = 3;
    else if (opstr=="!=") this->op = 4;
    else if (opstr=="<=") this->op = 5;
    else if (opstr=="=<") this->op = 5;
    else if (opstr==">=") this->op = 6;
    else if (opstr=="=>") this->op = 6;

    return true;
}

bool Group::execute(){

    // SORT RELATIONS
    tableStack.push(this->tableName);
    sortQuery.updateArgList(this->groupingColumn, 0);
    sortQuery.execute(1);
    this->tableName = tableStack.top();
    tableStack.pop();

    sortQuery.clear();

    // CREATE NEW TABLE

    Table* table = tableCatalogue.getTable(this->tableName);
    string newTableName = "GROUP_BY_RESULT";
    Table* newTable = new Table(newTableName, {this->groupingColumn, this->returnColumn});
    tableCatalogue.insertTable(newTable);

    // PERFORM GROUP BY
    vector<vector<int>> groupVec;
    int pageId = 0;
    MyCursor cursor = MyCursor(this->tableName, 0);
    vector<int> row = cursor.getRow();

    this->stats[this->conditionColumnId].min_ = row[this->conditionColumnId];
    this->stats[this->conditionColumnId].max_ = row[this->conditionColumnId];
    this->stats[this->conditionColumnId].sum_ = row[this->conditionColumnId];
    this->stats[this->conditionColumnId].count_ = 1;

    this->stats[this->returnColumnId].min_   = row[this->returnColumnId];
    this->stats[this->returnColumnId].max_   = row[this->returnColumnId];
    this->stats[this->returnColumnId].sum_   = row[this->returnColumnId];
    this->stats[this->returnColumnId].count_ = 1;

    this->currentGroupingFieldValue = row[this->groupingColumnId];

    for(int rowNumber = 1; rowNumber < table->rowCount; ++rowNumber){
        row = cursor.getRow();
        if(rowNumber == table->rowCount-1) fin = 1;
        if(this->updateStats(row)){
            groupVec.push_back(this->newRow);
            ++newTable->rowCount;
        }
        if(groupVec.size()==newTable->maxRowsPerBlock){
            bufferManager.writePage(newTableName, pageId++, groupVec, groupVec.size());
            ++newTable->blockCount;
            newTable->rowsPerBlockCount.push_back(groupVec.size());
            groupVec = {};
        }
    }
    this->newRow = {currentGroupingFieldValue, this->getStat(this->returnColumnId, this->returnFunction)};
    int conditionValue = this->getStat(this->conditionColumnId, this->conditionFunction);
    if(this->checkCondition(conditionValue)){
        groupVec.push_back(this->newRow);
        ++newTable->rowCount;
    }
    if(groupVec.size()>0){
        bufferManager.writePage(newTableName, pageId++, groupVec, groupVec.size());
        ++newTable->blockCount;
        newTable->rowsPerBlockCount.push_back(groupVec.size());
        groupVec = {};
    }
    // DELETE SORTED RELATION
    tableCatalogue.deleteTable(this->tableName);

    // ADD NEWLY CREATED TABLE TO STACK
    tableStack.push(newTableName);

    if(newTable->rowCount==0) {tableCatalogue.deleteTable(newTableName); return EXECUTION_SUCCESSFUL = false;}
    return EXECUTION_SUCCESSFUL = true;
}