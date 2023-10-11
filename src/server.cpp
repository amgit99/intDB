//Server Code
#include "globals.h"
#include "sort.h"
#include "join.h"
#include "group.h"

using namespace std;

// Parameters
float BLOCK_SIZE = 1;
uint BLOCK_COUNT = 2;
uint PRINT_COUNT = 5;

// Stats
uint BLOCKS_READ = 0;
uint BLOCKS_WRITTEN = 0;

// Global Objects
Logger logger;
Timer stopwatch;
TableCatalogue tableCatalogue;
MatrixCatalogue matrixCatalogue;
BufferManager bufferManager;

stack<string> tableStack;
stack<string> columnStack;
stack<string> operationStack;
stack<pair<int, string>> aggregateFunctionStack;
stack<int> intOperandStack;
bool __EOF__ = 0;

// Query Objects
Sort sortQuery; 
Order orderByQuery;
Join joinQuery;
Group groupByQuery;

void resetBlockStats(){
    BLOCKS_READ = 0;
    BLOCKS_WRITTEN = 0;
}

void printBlockStats(){
    cout << "Number of blocks read: " << BLOCKS_READ << endl;
    cout << "Number of blocks written: " << BLOCKS_WRITTEN << endl;
    cout << "Number of blocks accessed: " << BLOCKS_READ+BLOCKS_WRITTEN << endl;
}

int main(void){

    system("rm -rf ./data/temp");
    system("mkdir ./data/temp");

    while(yyparse()!=69);

    system("rm -rf ./data/temp");
    system("mkdir ./data/temp");
}