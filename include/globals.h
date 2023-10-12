#pragma once
#include "logger.h"
#include "timer.h"
#include "bufferManager.h"
#include "tableCatalogue.h"
#include "matrixCatalogue.h"
#include "mycursor.h"
#include "sort.h"
#include "order.h"
#include "join.h"
#include "group.h"
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

// DS
extern stack<string> evaluatedTable;
extern stack<string> tableStack;
extern stack<string> columnStack;
extern stack<string> operationStack;
extern stack<pair<int, string>> aggregateFunctionStack;
extern stack<int> intOperandStack;

// QUERY OBJECTS
extern Sort sortQuery;
extern Order orderByQuery;
extern Join joinQuery;
extern Group groupByQuery;
extern Cross crossQuery;
extern Selection selectionQuery;
extern Projection projectionQuery;


extern string RESULT_TABLE_NAME;
extern string CONDITION_BINOP;
extern string CONDITION_L_COLUMN_NAME;
extern string CONDITION_R_COLUMN_NAME;
extern int    CONDITION_R_INTVAL;