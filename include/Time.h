//
// Munaro Alex
//

#ifndef TIME_H
#define TIME_H

#include <vector>
#include <string>
using std::vector;
class Impianto;

using namespace std;

class Time {
private:
    int Hour, Minute;       //Orario corrente
    int CHour, CMinute;     //Orario cumulativo

public:
    //Costruttore di default
    Time() : Hour(0), Minute(0), CHour(0), CMinute(0) {}

    //Metodo per settare l'orario
    void SetTime(int hour, int minute);

    //Metodo per far avanzare il tempo eseguendo azioni automatiche
    void AdvanceTime(int hour, int minute, vector<Impianto*> imp);

    //Metodo che restituisce l'orario corrente in formato stringa "HH:MM"
    string toString() const;

    //Metodo per impostare l'orario corrente a partire da una stringa "HH:MM"
    void setFromString(const string& timeStr);


    //Metodi get
    int getHour() const { return Hour; }
    int getMinute() const { return Minute; }
    int getCHour() const { return CHour; }
    int getCMinute() const { return CMinute; }
};

#endif // TIME_H
