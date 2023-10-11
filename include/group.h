#pragma once
#include "base.h"

struct colStat{
    int count_;
    int max_;
    int min_;
    int sum_;
};

class Group {
    map<int, colStat> stats;
    vector<int> newRow;

    int currentGroupingFieldValue;
    int conditionFiledValue;
    int op;
    bool init = 1;
    bool fin = 0;

    string tableName;
    string groupingColumn;
    int groupingColumnId;
    string conditionColumn;
    int conditionColumnId;
    string returnColumn;
    int returnColumnId;
    int conditionFunction;
    int returnFunction;

public:
    int getStat(int colId, int fnId);
    bool checkCondition(int conditionValue);
    bool updateStats(vector<int> &row);
    bool checkArgs();
    bool execute();
};