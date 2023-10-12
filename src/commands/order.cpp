#include "globals.h"


bool Order::updateArgList(char* _columnName, bool columnOrder){
    string columnName = _columnName;

    if(tableCatalogue.isTable(tableStack.top())){
        cout<<"SEMANTIC ERROR: Assigned Relation already exist"<<endl;
        return false;
    }
    if(!tableCatalogue.isTable(this->tableName)){
        cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
        return false;
    }
    if(!tableCatalogue.isColumnFromTable(columnName, this->tableName)){
        cout<<"SEMANTIC ERROR: Column doesn't exist in relation"<<endl;
        return false;
    }
    this->columnName = columnName;
    this->order = columnOrder;
    return true;
}

bool Order::execute(){
    logger.log("Order:: exectute");
    tableStack.push(this->tableName);
    sortQuery.columnList.push_back(this->columnName);
    sortQuery.columnOrderList.push_back(this->order);
    sortQuery.execute(1);
    logger.log("Order:: LEFT exectute");
    return EXECUTION_SUCCESSFUL = true;
}