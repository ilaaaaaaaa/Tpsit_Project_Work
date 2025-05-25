//
// Rossi Samuele
//

#ifndef IMPIANTO_H
#define IMPIANTO_H

#include <iostream>
#include "Time.h"

using namespace std;

class Impianto {
protected:
    int id;
    bool modalita;
    float frequenza;
    float temperatura;
    bool stato;

    //Orario di inizio
    int IHour;
    int IMinute;

    //Orario di accensione
    int AHour;
    int AMinute;

    //Orario di spegnimento
    int SHour;
    int SMinute;

public:
    //Costruttore
    Impianto(int id, bool mod, float frequenza, float temperatura, bool stato, int hour, int minute, int ahour, int aminute, int shour, int sminute);

    //Metodi get
    int getId() const;
    int getAHour() const;
    int getAMinute() const;
    int getSHour() const;
    int getSMinute() const;

    //Metodo che alterna lo stato dell'impianto (acceso/spento) se la modalità e automatica
    void Automatica();

    //Metodo per attivare l’impianto manualmente, se non è già attivo
    void Attiva();

    //Metodo per disattivare l’impianto manualmente, se non è già spento
    void Disattiva();

    //Metodo per la stampa dello stato corrente dell’impianto (acceso/spento)
    void Stampa();

    //Metodi set
    void setStart(const Time& t);
    void setStop(const Time& t);
};




#endif //IMPIANTO_H