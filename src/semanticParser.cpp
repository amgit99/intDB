#include "globals.h"

bool fileExists(string name){
    string fileName = "./data/" + name + ".csv";
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}

bool isQueryFile(string fileName){
    fileName = "./data/" + fileName + ".ra";
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}