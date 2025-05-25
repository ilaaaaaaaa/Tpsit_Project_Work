//
// Munaro Alex
//

#ifndef TIME_H
#define TIME_H

#include <vector>
#include "Impianto.h"

using namespace std;

class Time {
private:
    int Hour, Minute;       //orario corrente
    int CHour, CMinute;     //orario cumulativo

public:
    Time() : Hour(0), Minute(0), CHour(0), CMinute(0) {}

    void SetTime(int hour, int minute);
    void AdvanceTime(int hour, int minute, vector<Impianto*> imp);
    string toString() const;
    void setFromString(const string& timeStr);


    //getter
    int getHour() const { return Hour; }
    int getMinute() const { return Minute; }
    int getCHour() const { return CHour; }
    int getCMinute() const { return CMinute; }
};

#endif // TIME_H
