#include"semanticParser.h"

void executeCommand();

void executeCLEAR();
void executeCROSS();
void executeDISTINCT();
void executeEXPORT();
void executeINDEX();
void executeJOIN();
void executeLIST();
void executeLOAD();
void executePRINT(char* _tableName);
void executePROJECTION();
void executeRENAME(char* _oldCol, char* _newCol, char* _tableName);
void executeSELECTION();
void executeSORT();
void executeSOURCE(char* fileName);
void executeLOADMATRIX(char* matrixName);
void executePRINTMATRIX(char* matrixName);
void executeTRANSPOSEMATRIX(char* matrixName);
void executeRENAMEMATRIX(char* oldName, char* newName);
void executeEXPORTMATRIX(char* matrixName);
void executeCHECKSYMMETRY(char* matrixName);
void executeCOMPUTE(char* matrixName);

bool evaluateBinOp(int value1, int value2, BinaryOperator binaryOperator);
void printRowCount(int rowCount);