#pragma once
#include "base.h"

class Timer{
    vector<std::chrono::high_resolution_clock::time_point> splits;
    
public:
    void lap();
    void showSplits();

};

extern Timer stopwatch;