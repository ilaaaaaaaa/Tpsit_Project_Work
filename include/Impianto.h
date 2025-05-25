//
// Rossi Samuele
//

#ifndef IMPIANTO_H
#define IMPIANTO_H

#include <iostream>

using namespace std;

class Impianto {
protected:
    int id;
    bool modalita;
    float frequenza;
    float temperatura;
    bool stato;
    int IHour;
    int IMinute;
    int AHour;
    int AMinute;
    int SHour;
    int SMinute;

public:

    Impianto(int id, bool mod, float frequenza, float temperatura, bool stato, int hour, int minute, int ahour, int aminute, int shour, int sminute);
    int getId() const;
    int getAHour() const;
    int getAMinute() const;
    int getSHour() const;
    int getSMinute() const;
    void Automatica();
};




#endif //IMPIANTO_H