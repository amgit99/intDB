#pragma once
#include "page.h"
/**
 * @brief The cursor is an important component of the system. To read from a
 * table, you need to initialize a cursor. The cursor reads rows from a page one
 * at a time.
 *
 */
class MyCursor{
    public:
    string tableName;
    Page page;
    int pageIndex;
    int rowOffset;
    int blockRowCount;
    int rowCount;
    long long rowNumber;

    public:
    MyCursor(string tableName, int pageIndex);
    MyCursor(string tableName, long long rowIndex);
    vector<int> getRow();
};