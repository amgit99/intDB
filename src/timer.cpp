#include "global.h"

void Timer::lap(){
    splits.push_back(std::chrono::high_resolution_clock::now());
}

void Timer::showSplits(){
    for(int i=1; i<splits.size(); ++i){
        std::chrono::duration<double, std::milli> interval = splits[i]-splits[i-1];
        cout << (interval.count()) << " ms" << endl;
    }
}