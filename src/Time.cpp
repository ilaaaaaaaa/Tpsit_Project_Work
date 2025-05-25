//
// Munaro Alex
//

#include "../include/Time.h"
#include "../include/Impianto.h"
#include <iostream>

using namespace std;

void Time::SetTime(int hour, int minute) {
    if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60) {
        Hour = hour;
        Minute = minute;
    } else {
        cout << "Valori invalidi" << std::endl;
    }
}

void Time::AdvanceTime(int hour, int minute, vector<Impianto*> imp) {
    if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60) {
        cout << "Valori invalidi" << endl;
        return;
    }

    int totalMinutesPassed = hour * 60 + minute;

    for (auto n : imp) {
        int startMin = n->getSHour() * 60 + n->getSMinute();
        int stopMin = n->getAHour() * 60 + n->getAMinute();
        int interval = stopMin - startMin;

        if (interval <= 0) continue;

        int k = totalMinutesPassed / interval;
        while (k-- > 0) {
            n->Automatica();
        }
    }

    // aggiorna tempo cumulativo
    CMinute += totalMinutesPassed;
    CHour += CMinute / 60;
    CMinute %= 60;

    // aggiorna orario corrente
    int currentTotal = Hour * 60 + Minute + totalMinutesPassed;
    Hour = (currentTotal / 60) % 24;
    Minute = currentTotal % 60;
}

string Time::toString() const {
    char buffer[6];
    buffer[0] = Hour / 10 + '0';
    buffer[1] = Hour % 10 + '0';
    buffer[2] = ':';
    buffer[3] = Minute / 10 + '0';
    buffer[4] = Minute % 10 + '0';
    buffer[5] = '\0';
    return string(buffer);
}

void Time::setFromString(const string& timeStr) {
    if (timeStr.length() != 5 || timeStr[2] != ':') {
        cout << "Formato orario non valido. Usa HH:MM.\n";
        return;
    }

    int h = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
    int m = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');

    SetTime(h, m);
}