#pragma once
#include "logger.h"

class Sort{
    string tableName;
    vector<string> columnList;
    vector<bool> columnOrderList;

public:
    bool setTableName(char* tableName);
    bool updateArgList(char* columnName, bool columnOrder);
};