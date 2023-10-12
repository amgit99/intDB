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
bool EXECUTION_SUCCESSFUL = 0;

// Assignment Statement Result Table Name
string RESULT_TABLE_NAME = "";

// Selection Statement attributes
string CONDITION_L_COLUMN_NAME = "";
string CONDITION_BINOP = "";
int    CONDITION_R_INTVAL = 0;
string CONDITION_R_COLUMN_NAME = "";

// Query Objects
Sort sortQuery; 
Order orderByQuery;
Join joinQuery;
Group groupByQuery;
Cross crossQuery; 
Selection selectionQuery; 
Projection projectionQuery;

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

    while(true) {
        cout << "> ";
        if(yyparse()==69) break;
    }

    system("rm -rf ./data/temp");
    system("mkdir ./data/temp");
}