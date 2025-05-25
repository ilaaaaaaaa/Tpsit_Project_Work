//
// Rossi Samuele
//

#include <iostream>
#include "../include/Impianto.h"

using namespace std;

//Costruttore
Impianto::Impianto(int id, bool mod, float frequenza, float temperatura, bool stato, int hour, int minute, int ahour, int aminute, int shour, int sminute): id(id), modalita(mod), frequenza(frequenza), temperatura(temperatura), stato(stato), IHour(hour), IMinute(minute), AHour(ahour), AMinute(aminute), SHour(shour), SMinute(sminute){}

//Metodi get
int Impianto::getId() const {
    return id;
}

int Impianto::getAHour() const {
    return AHour;
}

int Impianto::getAMinute() const {
    return AMinute;
}

int Impianto::getSHour() const {
    return SHour;
}

int Impianto::getSMinute() const {
    return SMinute;
}

//Metodo che alterna lo stato dell'impianto (acceso/spento) se la modalità e automatica
void Impianto::Automatica(){
    if(modalita) {
        stato = !stato;
        if(stato)
            cout << "L'impianto " << id << "è acceso" << endl;
        else
            cout << "L'impianto " << id << "è spento" << endl;
    }
}

//Metodo per attivare l’impianto manualmente, se non è già attivo
void Impianto::Attiva() {
    if(!stato) {
        cout << "L'impianto " << id << "è acceso" << endl;
        stato = true;
    }
    else
        cout << "L'impianto " << id << "è gia' attivo" << endl;
}

//Metodo per disattivare l’impianto manualmente, se non è già spento
void Impianto::Disattiva() {
    if(stato) {
        cout << "L'impianto " << id << "è spento" << endl;
        stato = false;
    }
    else
        cout << "L'impianto " << id << "è gia' spento" << endl;
}

//Metodo per la stampa dello stato corrente dell’impianto (acceso/spento)
void Impianto::Stampa() {
    if(stato)
        cout << "L'impianto " << id << "è acceso" << endl;
    else
        cout << "L'impianto " << id << "è spento" << endl;
}

//Metodi set
void Impianto::setStart(const Time& t) {
    SHour = t.getHour();
    SMinute = t.getMinute();
}

void Impianto::setStop(const Time& t) {
    AHour = t.getHour();
    AMinute = t.getMinute();
}
