#pragma once
#include "logger.h"
#include "table.h"

class Sort{
public:

    Table *table;
    vector<string> columnList = {};
    vector<bool> columnOrderList = {};
    vector<pair<int, bool>> sortConstraints = {};

    bool updateArgList(char* columnName, bool columnOrder);
    bool execute();
    void merge(long long setSize, int stack1, int stack2);
};