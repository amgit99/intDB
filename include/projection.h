#pragma once

class Projection{
    public:
        string resultTableName;
        deque<string> projectedColumns;
        string sourceTableName;

        void clear();
};