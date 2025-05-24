//
// Created by ilame on 12/05/2025.
//
#include "../include/Time.h"
#include <vector>
#include "../include/Impianto.h"

#include <iostream>

using namespace std;

void Time::SetTime (int hour, int minute) {
    if(hour<24&&minute<60) {
        Hour = hour;
        Minute = minute;
    }
    else
        std::cout<<"Valori invalidi"<<std::endl;
}

void Time::AdvanceTime(int hour, int minute, std::vector<Impianto*> imp) {
    if(hour<24&&minute<60) {
        int totMin, k;
        int TPassato = hour*60 + minute;
        for(auto n : imp) {
            totMin = n->getSHour()*60+n->getSMinute()-n->getSMinute()*60-n->getSMinute();
            k=TPassato/totMin;
            while(k!=0) {
                n->Automatica();
                k--;
            }
            CMinute+=TPassato%60;
            CHour+=TPassato/60;
        }
    }
    else
        std::cout<<"Valori invalidi"<<std::endl;
}