#pragma once
#include "logger.h"
#include "timer.h"
#include "bufferManager.h"
#include "tableCatalogue.h"
#include "matrixCatalogue.h"
#include "mycursor.h"
#include "sort.h"
#include "cross.h"
#include "binop.h"
#include "selection.h"
#include "projection.h"

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


extern stack<string> evaluatedTable;
extern Sort sortQuery;

extern string RESULT_TABLE_NAME;

extern Cross crossQuery;

extern string CONDITION_L_COLUMN_NAME;
extern string CONDITION_BINOP;
extern int    CONDITION_R_INTVAL;
extern string CONDITION_R_COLUMN_NAME;
extern Selection selectionQuery;
extern Projection projectionQuery;


