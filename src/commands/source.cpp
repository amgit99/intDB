#include "globals.h"
#include "semanticParser.h"

extern FILE *yyin;
/**
 * @brief 
 * SYNTAX: SOURCE filename
 */

bool semanticParseSOURCE(char* fileName){
    string file = fileName;
    logger.log("semanticParseSOURCE");
    if (!isQueryFile(file)){
        cout << "SEMANTIC ERROR: File doesn't exist" << endl;
        return false;
    }
    return true;
}

void executeSOURCE(char* fileName){
    string _, file = fileName;
    logger.log("executeSOURCE");
    string path = "./data/" + file + ".ra";
    logger.log(path);

    FILE *input_file = fopen(path.c_str(), "r");
    yyin = input_file;
    __EOF__ = 0;
    while(!__EOF__ ) { cout << "> "; yyparse(); } 
    fclose(input_file);
}