//
// Munaro Alex
//

#include "../include/Time.h"
#include "../include/Impianto.h"
#include <iostream>

using namespace std;

//Metodo che imposta l'orario corrente (se i valori sono validi)
void Time::SetTime(int hour, int minute) {
    if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60) {
        Hour = hour;
        Minute = minute;
    } else {
        cout << "Valori invalidi" << std::endl;
    }
}

//Metodo che fa avanzare il tempo di una certa quantità e gestisce l'automazione degli impianti
void Time::AdvanceTime(int hour, int minute, vector<Impianto*> imp) {
    //Controllo su valori validi
    if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60) {
        cout << "Valori invalidi" << endl;
        return;
    }

    //Converte il tempo passato in minuti totali
    int totalMinutesPassed = hour * 60 + minute;

    //Per ogni impianto, calcola l'intervallo tra accensione e spegnimento
    for (auto n : imp) {
        int startMin = n->getSHour() * 60 + n->getSMinute();
        int stopMin = n->getAHour() * 60 + n->getAMinute();
        int interval = stopMin - startMin;

        //Se l'intervallo non è valido o nullo, salta
        if (interval <= 0) continue;

        //Calcola quante volte si ripete il ciclo on/off durante il tempo passato
        int k = totalMinutesPassed / interval;

        //Applica lo stato automatico k volte
        while (k-- > 0) {
            n->Automatica();
        }
    }

    //Aggiorna il tempo cumulativo
    CMinute += totalMinutesPassed;
    CHour += CMinute / 60;   //Gestione overflow dei minuti
    CMinute %= 60;

    //Aggiorna l'orario corrente, mantenendo il formato 24h
    int currentTotal = Hour * 60 + Minute + totalMinutesPassed;
    Hour = (currentTotal / 60) % 24;
    Minute = currentTotal % 60;
}

//Metodo che converte l'orario corrente in una stringa formattata "HH:MM"
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

//Metodo che imposta l'orario a partire da una stringa nel formato "HH:MM"
void Time::setFromString(const string& timeStr) {
    // Controllo sul formato valido
    if (timeStr.length() != 5 || timeStr[2] != ':') {
        cout << "Formato orario non valido. Usa HH:MM.\n";
        return;
    }

    //Converte i caratteri in numeri per ore e minuti
    int h = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
    int m = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');

    //Imposta l'orario
    SetTime(h, m);
}
