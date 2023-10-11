#pragma once
#include "logger.h"
#include "table.h"

class Order{
public:

    string columnName;
    string tableName;
    bool order;

    bool updateArgList(char* _columnName, bool columnOrder);
    bool execute();
};