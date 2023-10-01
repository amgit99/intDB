#include "globals.h"
/**
 * @brief File contains method to process SORT commands.
 * 
 * syntax:
 * R <- SORT relation_name BY column_name IN sorting_order
 * 
 * sorting_order = ASC | DESC 
 */

// bool syntacticParseSORT(){
//     logger.log("syntacticParseSORT");
//     if(tokenizedQuery.size()!= 8 || tokenizedQuery[4] != "BY" || tokenizedQuery[6] != "IN"){
//         cout<<"SYNTAX ERROR"<<endl;
//         return false;
//     }
//     parsedQuery.queryType = SORT;
//     parsedQuery.sortResultRelationName = tokenizedQuery[0];
//     parsedQuery.sortRelationName = tokenizedQuery[3];
//     parsedQuery.sortColumnName = tokenizedQuery[5];
//     string sortingStrategy = tokenizedQuery[7];
//     if(sortingStrategy == "ASC")
//         parsedQuery.sortingStrategy = ASC;
//     else if(sortingStrategy == "DESC")
//         parsedQuery.sortingStrategy = DESC;
//     else{
//         cout<<"SYNTAX ERROR"<<endl;
//         return false;
//     }
//     return true;
// }

// class Sort{ 
// // These vectors hold the parameters of the query that are the 
// // column names and the order on which they are to be sorted. 

// vector<string> columnList;
// vector<bool> columnOrderList;

// public:

    

// };

bool semanticParseSORT(){
    logger.log("semanticParseSORT");

    // if(!tableCatalogue.isTable(column)){
    //     cout<<"SEMANTIC ERROR: Relation doesn't exist"<<endl;
    //     return false;
    // }

    // if(!tableCatalogue.isColumnFromTable(column, parsedQuery.sortRelationName)){
    //     cout<<"SEMANTIC ERROR: Column doesn't exist in relation"<<endl;
    //     return false;
    // }

    return true;
}

void executeSORT(){
    logger.log("executeSORT");
    // for(auto itr: columnList) cout << itr << "  "; cout << endl;
    // reverse(columnOrderList.begin(), columnOrderList.end());
    // for(auto itr: columnOrderList) cout << itr << "  "; cout << endl;

    return;
}