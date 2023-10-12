#pragma once

enum SelectType{
    COLUMN,
    INT_LITERAL,
    NO_SELECT_CLAUSE
};

// bool semanticParseSELECTION();

class Selection{
    public:
        string resultTableName;
        string lcolumnName;
        string binop;
        int rIntValue;
        string rcolumnName;
        string sourceTableName;
        SelectType selectType = NO_SELECT_CLAUSE;

        void clear();

};