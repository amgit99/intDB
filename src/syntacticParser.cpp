#include "global.h"

bool syntacticParse(){
    logger.log("syntacticParse");
    string possibleQueryType = tokenizedQuery[0];

    if (tokenizedQuery.size() < 2){
        cout << "SYNTAX ERROR" << endl;
        return false;
    }

    if (possibleQueryType == "CLEAR")
        return syntacticParseCLEAR();
    else if (possibleQueryType == "INDEX")
        return syntacticParseINDEX();
    else if (possibleQueryType == "LIST");
        // return syntacticParseLIST();
    else if (possibleQueryType == "LOAD"){
        if(tokenizedQuery[1] == "MATRIX" && tokenizedQuery.size() > 2){
            // return syntacticParseLOADMATRIX();
            return 0;
        }
        return syntacticParseLOAD();
    }
    else if (possibleQueryType == "PRINT"){
        if(tokenizedQuery[1] == "MATRIX"){
            // return syntacticParsePRINTMATRIX();
            return 0;
        }
        // return syntacticParsePRINT();
    }
    else if (possibleQueryType == "RENAME"){
        if(tokenizedQuery[1] == "MATRIX"){
            // return syntacticParseRENAMEMATRIX();
            return 0;
        }
        // return syntacticParseRENAME();
    }
    else if(possibleQueryType == "EXPORT"){
        if(tokenizedQuery[1] == "MATRIX"){
            // return syntacticParseEXPORTMATRIX();
            return 0;
        }
        return syntacticParseEXPORT();
    }
    else if(possibleQueryType == "SOURCE"){
        // return syntacticParseSOURCE();
        return 0;
    }
    else if(possibleQueryType == "TRANSPOSE"){
        if(tokenizedQuery[1] == "MATRIX"){
            // return syntacticParseTRANSPOSEMATRIX();
            return 0;
        }
    }
    else if(possibleQueryType == "CHECKSYMMETRY"){
        // return syntacticParseCHECKSYMMETRY();
        return 0;
    }
    else if(possibleQueryType == "COMPUTE"){
        // return syntacticParseCOMPUTE();
        return 0;
    }
    else{
        string resultantRelationName = possibleQueryType;
        if (tokenizedQuery[1] != "<-" || tokenizedQuery.size() < 3){
            cout << "SYNTAX ERROR" << endl;
            return false;
        }
        possibleQueryType = tokenizedQuery[2];
        if (possibleQueryType == "PROJECT")
            return syntacticParsePROJECTION();
        else if (possibleQueryType == "SELECT")
            return syntacticParseSELECTION();
        else if (possibleQueryType == "JOIN")
            return syntacticParseJOIN();
        else if (possibleQueryType == "CROSS")
            return syntacticParseCROSS();
        else if (possibleQueryType == "DISTINCT")
            return syntacticParseDISTINCT();
        else if (possibleQueryType == "SORT")
            return syntacticParseSORT();
        else {
            cout << "SYNTAX ERROR" << endl;
            return false;
        }
    }
    return false;
}

ParsedQuery::ParsedQuery(){
}

void ParsedQuery::clear(){
    logger.log("ParseQuery::clear");
    this->queryType = UNDETERMINED;

    this->clearRelationName = "";

    this->crossResultRelationName = "";
    this->crossFirstRelationName = "";
    this->crossSecondRelationName = "";

    this->distinctResultRelationName = "";
    this->distinctRelationName = "";

    this->exportRelationName = "";

    this->indexingStrategy = NOTHING;
    this->indexColumnName = "";
    this->indexRelationName = "";

    this->joinBinaryOperator = NO_BINOP_CLAUSE;
    this->joinResultRelationName = "";
    this->joinFirstRelationName = "";
    this->joinSecondRelationName = "";
    this->joinFirstColumnName = "";
    this->joinSecondColumnName = "";

    this->loadRelationName = "";

    this->printRelationName = "";

    this->projectionResultRelationName = "";
    this->projectionColumnList.clear();
    this->projectionRelationName = "";

    this->renameFromColumnName = "";
    this->renameToColumnName = "";
    this->renameRelationName = "";

    this->selectType = NO_SELECT_CLAUSE;
    this->selectionBinaryOperator = NO_BINOP_CLAUSE;
    this->selectionResultRelationName = "";
    this->selectionRelationName = "";
    this->selectionFirstColumnName = "";
    this->selectionSecondColumnName = "";
    this->selectionIntLiteral = 0;

    this->sortingStrategy = NO_SORT_CLAUSE;
    this->sortResultRelationName = "";
    this->sortColumnName = "";
    this->sortRelationName = "";

    this->sourceFileName = "";
}