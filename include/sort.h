#pragma once
#include "logger.h"
#include "table.h"

class Sort{
public:

    Table *table;
    string tableName;
    vector<string> columnList = {};
    vector<bool> columnOrderList = {};
    vector<pair<int, bool>> sortConstraints = {};

    bool updateArgList(string columnName, bool columnOrder);
    bool execute(bool makeCopy);
    int merge(long long setSize, int stack1, int stack2);
    void clear();
};