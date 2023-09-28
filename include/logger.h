#include "timer.h"

using namespace std;

class Logger{

    string logFile = "log";
    ofstream fout;
    
public:

    Logger();
    void log(string logString);
};

extern Logger logger;