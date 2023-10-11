#pragma once
#include "table.h" 

class Join{
public:
    string table1Name;
    string table1column;
    int column1index;
    string table2Name;
    string table2column;
    int column2index;
    int op;

    bool comp(int a, int b);
    bool checkArgs();
    void execute();
};