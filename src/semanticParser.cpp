#include"global.h"

bool semanticParse(){
    logger.log("semanticParse");
    switch(parsedQuery.queryType){
        case CLEAR: return semanticParseCLEAR();
        case CROSS: return semanticParseCROSS();
        case DISTINCT: return semanticParseDISTINCT();
        case EXPORT: return semanticParseEXPORT(); 
        case INDEX: return semanticParseINDEX();
        case JOIN: return semanticParseJOIN();
        // case LIST: return semanticParseLIST();
        case LOAD: return semanticParseLOAD();
        // case PRINT: return semanticParsePRINT();
        case PROJECTION: return semanticParsePROJECTION();
        // case RENAME: return semanticParseRENAME();
        case SELECTION: return semanticParseSELECTION();
        case SORT: return semanticParseSORT();
        // case SOURCE: return semanticParseSOURCE();
        // case LOAD_MATRIX: return semanticParseLOADMATRIX();
        // case PRINT_MATRIX: return semanticParsePRINTMATRIX();
        // case TRANSPOSE_MATRIX: return semanticParseTRANSPOSEMATRIX();
        // case EXPORT_MATRIX: return semanticParseEXPORTMATRIX();
        // case RENAME_MATRIX: return semanticParseRENAMEMATRIX();
        // case CHECKSYMMETRY: return semanticParseCHECKSYMMETRY();
        // case COMPUTE: return semanticParseCOMPUTE();
        default: cout<<"SEMANTIC ERROR"<<endl;
    }

    return false;
}

bool fileExists(string name){
    string fileName = "./data/" + name + ".csv";
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}

bool isQueryFile(string fileName){
    fileName = "./data/" + fileName + ".ra";
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}