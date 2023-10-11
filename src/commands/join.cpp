#include "globals.h"
#include "join.h"


bool Join::comp(int a, int b){
    switch (this->op) {
        case 1: return a > b;
        case 2: return a >= b;
        case 3: return a == b;
        case 4: return a != b;
        default: return 0;
    }
}

bool Join::checkArgs(){
    this->table2Name = tableStack.top();
    tableStack.pop();
    this->table1Name = tableStack.top();
    tableStack.pop();
    if(!tableCatalogue.isTable(this->table2Name)){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }
    if(!tableCatalogue.isTable(this->table1Name)){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }

    this->table2column = columnStack.top();
    columnStack.pop();
    this->table1column = columnStack.top();
    columnStack.pop();
    if(!tableCatalogue.isColumnFromTable(this->table2column, this->table2Name)){
        cout<<"SEMANTIC ERROR: Column "<< this->table2column <<" doesn't exist in relation " << this->table2Name <<endl;
        return false;
    }
    this->column2index = tableCatalogue.getTable(this->table2Name)->getColumnIndex(this->table2column);
    if(!tableCatalogue.isColumnFromTable(this->table1column, this->table1Name)){
        cout<<"SEMANTIC ERROR: Column "<< this->table1column <<" doesn't exist in relation" << this->table1Name << endl;
        return false;
    }
    this->column1index = tableCatalogue.getTable(this->table1Name)->getColumnIndex(this->table1column);

    string opstr = operationStack.top();
    operationStack.pop();
    if(opstr==">") {
        this->op = 1;
    } else if (opstr == "<"){
        this->op = 1;
        swap(this->table1Name, this->table2Name);
        swap(this->table1column, this->table2column);
        swap(this->column1index, this->column2index);
    } else if (opstr == ">=") {
        this->op = 2;
    } else if (opstr == "=>") {
        this->op = 2;
    } else if (opstr == "<=") {
        this->op = 2;
        swap(this->table1Name, this->table2Name);
        swap(this->table1column, this->table2column);
        swap(this->column1index, this->column2index);
    } else if (opstr == "=<") {
        this->op = 2;
        swap(this->table1Name, this->table2Name);
        swap(this->table1column, this->table2column);
        swap(this->column1index, this->column2index);
    } else if (opstr == "==") {
        this->op = 3;
    } else if (opstr == "!=") {
        this->op = 4;
    } else {
        cout << "INVALID OPERAND" << endl;
    }
    return true;
}

void Join::execute(){

    // SORT RELATIONS
    tableStack.push(this->table1Name);
    sortQuery.updateArgList(this->table1column, 0);
    sortQuery.execute(1);
    this->table1Name = tableStack.top();
    tableStack.pop();

    sortQuery.clear();

    tableStack.push(this->table2Name);
    sortQuery.updateArgList(this->table2column, 0);
    sortQuery.execute(1);
    this->table2Name = tableStack.top();
    tableStack.pop();

    sortQuery.clear();

    // create new table
    Table* table1 = tableCatalogue.getTable(this->table1Name);
    Table* table2 = tableCatalogue.getTable(this->table2Name);
    vector<string> joinTableColumns;
    joinTableColumns.insert(joinTableColumns.end(), table1->columns.begin(), table1->columns.end());
    joinTableColumns.insert(joinTableColumns.end(), table2->columns.begin(), table2->columns.end());
    string joinedTableName = "JOINRESULT";
    Table* joinedTable = new Table(joinedTableName, joinTableColumns);
    tableCatalogue.insertTable(joinedTable);

    // perform join
    vector<vector<int>> joinTablePage;
    int joinPageIndex = 0;
    vector<int> joinTableRow;

    for(int pageIndexL = 0; pageIndexL < table1->blockCount; ++pageIndexL ){
        Page pageL = bufferManager.getPage(this->table1Name, pageIndexL);
        for(int pageIndexR = 0; pageIndexR < table2->blockCount; ++pageIndexR ){
            Page pageR = bufferManager.getPage(this->table2Name, pageIndexR);
            for(int lineL = 0; lineL < pageL.rowCount; ++lineL){
                vector<int> rowL = pageL.rows[lineL];
                for(int lineR = 0; lineR < pageR.rowCount; ++lineR){
                    vector<int> rowR = pageR.rows[lineR];
                    if(comp(rowL[this->column1index], rowR[this->column2index])){
                        vector<int> newRow;
                        newRow.insert(newRow.end(), rowL.begin(), rowL.end());
                        newRow.insert(newRow.end(), rowR.begin(), rowR.end());
                        joinTablePage.push_back(newRow);
                        ++joinedTable->rowCount;
                        if(joinTablePage.size()==joinedTable->maxRowsPerBlock){
                            bufferManager.writePage(joinedTableName, joinPageIndex++, joinTablePage, joinTablePage.size());
                            ++joinedTable->blockCount;
                            joinedTable->rowsPerBlockCount.push_back(joinTablePage.size());
                            joinTablePage = {};
                        }
                    } else if (this->op == 3 && rowR[this->column2index] < rowL[this->column1index]){
                        continue;
                    } else if (this->op == 4) {
                        continue;
                    } else break;
                }
            }
        }
    }
    if(joinTablePage.size()>0){
        bufferManager.writePage(joinedTableName, joinPageIndex++, joinTablePage, joinTablePage.size());
        ++joinedTable->blockCount;
        joinedTable->rowsPerBlockCount.push_back(joinTablePage.size());
        joinTablePage = {};
    }

    // delete sorted relations
    tableCatalogue.deleteTable(this->table1Name);
    tableCatalogue.deleteTable(this->table2Name);

    // add newly created table to stack
    tableStack.push(joinedTableName);
}