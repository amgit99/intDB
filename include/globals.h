#pragma once
#include "base.h"
#include "logger.h"
#include "timer.h"
#include "bufferManager.h"
#include "tableCatalogue.h"
#include "matrixCatalogue.h"

extern float BLOCK_SIZE;
extern uint BLOCK_COUNT;
extern uint PRINT_COUNT;
extern uint BLOCKS_READ;
extern uint BLOCKS_WRITTEN;
extern vector<string> tokenizedQuery;
extern TableCatalogue tableCatalogue;
extern MatrixCatalogue matrixCatalogue;
extern BufferManager bufferManager;
extern bool __EOF__;
extern string command;
extern void resetBlockStats();
void printBlockStats();
extern bool process_input();
int yyparse();