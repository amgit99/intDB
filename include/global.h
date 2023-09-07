// #pragma once
#include"executor.h"

extern float BLOCK_SIZE;
extern uint BLOCK_COUNT;
extern uint PRINT_COUNT;
extern uint BLOCKS_READ;
extern uint BLOCKS_WRITTEN;
extern vector<string> tokenizedQuery;
extern ParsedQuery parsedQuery;
extern TableCatalogue tableCatalogue;
extern MatrixCatalogue matrixCatalogue;
extern BufferManager bufferManager;
extern bool __SOURCE;
extern string command;
extern void resetBlockStats();
void printBlockStats();
extern bool process_input();