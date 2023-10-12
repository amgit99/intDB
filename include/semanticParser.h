#pragma once
#include "base.h"

bool semanticParse();

bool semanticParseCLEAR(char* _tableName);
bool semanticParseCROSS();
bool semanticParseDISTINCT();
bool semanticParseEXPORT(char* _tableName);
bool semanticParseINDEX();
bool semanticParseJOIN();
bool semanticParseLIST();
bool semanticParseLOAD(char* _tableName);
bool semanticParsePRINT(char* _tableName);
bool semanticParsePROJECTION();
bool semanticParseRENAME(char* _oldCol, char* _newCol, char* _tableName);
bool semanticParseSELECTION();
bool semanticParseSORT();
bool semanticParseSOURCE(char* fileName);
bool semanticParseLOADMATRIX(char* matrixName);
bool semanticParsePRINTMATRIX(char* matrixName);
bool semanticParseTRANSPOSEMATRIX(char* matrixName);
bool semanticParseRENAMEMATRIX(char* oldName, char* newName);
bool semanticParseEXPORTMATRIX(char* matrixName);
bool semanticParseCHECKSYMMETRY(char* matrixName);
bool semanticParseCOMPUTE(char* matrixName);

bool fileExists(string name);
bool isQueryFile(string fileName);