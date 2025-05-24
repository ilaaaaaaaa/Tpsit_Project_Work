//
// Created by ilame on 12/05/2025.
//
#include <vector>
#include "../include/Impianto.h"

#ifndef TIME_H
#define TIME_H

using namespace std;
class Time {

public:
    int Hour, Minute, CHour, CMinute;
    Time():CHour(0),CMinute(0){}
    void SetTime(int hour, int minute);
    void AdvanceTime(int hour, int minute, std::vector<Impianto*> imp);
};




#endif