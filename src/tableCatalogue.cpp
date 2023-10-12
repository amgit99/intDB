#include "globals.h"

void TableCatalogue::insertTable(Table* table){
    logger.log("TableCatalogue::insertTable"); 
    this->tables[table->tableName] = table;
}
void TableCatalogue::deleteTable(string tableName){
    logger.log("TableCatalogue::deleteTable"); 
    this->tables[tableName]->unload();
    delete this->tables[tableName];
    this->tables.erase(tableName);
}
void TableCatalogue::renameTable(string oldTable, string newTable){
    logger.log("TableCatalogue::renameTable");
    if(this->isTable(newTable)) cout << "ASSIGNED RELATION NAME TAKEN" << endl;
    if(!this->isTable(oldTable)) cout << "TABLE DOES NOT EXIST" << endl;
    Table* table = this->tables[oldTable];
    table->tableName = newTable;
    this->tables[newTable] = table;
    this->tables.erase(oldTable);

    logger.log("TableCatalogue::catalogue Updated");

    for(int i=0; i<table->blockCount; ++i){
        string ofn = oldTable+"_Page"+to_string(i);
        string nfn = newTable+"_Page"+to_string(i);
        ofn = "data/temp/"+ofn; nfn = "data/temp/"+nfn;
        string command = "mv -f "+ofn+" "+nfn;
        system(command.c_str());
    }
    logger.log("TableCatalogue::LEFT renameTable");
}

Table* TableCatalogue::getTable(string tableName){
    logger.log("TableCatalogue::getTable");
    logger.log(tableName);
    logger.log(to_string(this->tables.size()));
    logger.log("TableCatalogue::Left getTable");
    return this->tables[tableName];
}
bool TableCatalogue::isTable(string tableName){
    logger.log("TableCatalogue::isTable"); 
    if (this->tables.count(tableName))
        return true;
    return false;
}

bool TableCatalogue::isColumnFromTable(string columnName, string tableName){
    logger.log("TableCatalogue::isColumnFromTable"); 
    if (this->isTable(tableName)){
        Table* table = this->getTable(tableName);
        if (table->isColumn(columnName))
            return true;
    }
    return false;
}

void TableCatalogue::print(){
    logger.log("TableCatalogue::print"); 
    cout << "\nRELATIONS" << endl;

    int rowCount = 0;
    for (auto rel : this->tables){
        cout << rel.first << endl;
        rowCount++;
    }
    cout << "\n\nRow Count: " << rowCount << endl;
}

TableCatalogue::~TableCatalogue(){
    logger.log("TableCatalogue::~TableCatalogue"); 
    for(auto table: this->tables){
        table.second->unload();
        delete table.second;
    }
}
