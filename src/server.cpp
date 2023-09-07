//Server Code
#include "global.h"

using namespace std;

float BLOCK_SIZE = 1;
uint BLOCK_COUNT = 2;
uint PRINT_COUNT = 20;

// stats
uint BLOCKS_READ = 0;
uint BLOCKS_WRITTEN = 0;


string command;
Logger logger;
vector<string> tokenizedQuery;
ParsedQuery parsedQuery;
TableCatalogue tableCatalogue;
MatrixCatalogue matrixCatalogue;
BufferManager bufferManager;
bool __SOURCE = 0;

void resetBlockStats(){
    BLOCKS_READ = 0;
    BLOCKS_WRITTEN = 0;
}

void printBlockStats(){
    cout << "Number of blocks read: " << BLOCKS_READ << endl;
    cout << "Number of blocks written: " << BLOCKS_WRITTEN << endl;
    cout << "Number of blocks accessed: " << BLOCKS_READ+BLOCKS_WRITTEN << endl;
}

void doCommand(){
    logger.log("doCommand");
    if (syntacticParse() && semanticParse())
        executeCommand();
    return;
}

bool process_input(){

    tokenizedQuery.clear();
    parsedQuery.clear();

    if(!__SOURCE) {
        logger.log("\nReading New Command: ");
        cout << "\n> ";
        getline(cin, command);
    }

    regex delim("[^\\s,]+");
    auto words_begin = std::sregex_iterator(command.begin(), command.end(), delim);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        tokenizedQuery.emplace_back((*i).str());

    if (tokenizedQuery.size() == 1 && tokenizedQuery.front() == "QUIT") return 1;
    if (tokenizedQuery.empty()) return 0;
    if (tokenizedQuery.size() == 1){
        cout << "SYNTAX ERROR" << endl;
        return 0;
    }

    doCommand();
    return 0;
}

int main(void){

    system("rm -rf ./data/temp");
    system("mkdir ./data/temp");

    bool quit = 0;
    while(!quit){
        quit = process_input();
    }
}