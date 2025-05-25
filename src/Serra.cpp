//
// Munaro Alex - Meggiolaro Ilaria
//

#include "../include/Serra.h"
#include "../include/Impianto.h"
#include "../include/Time.h"

#include <iostream>

using namespace std;

Impianto* Serra::aggiungiImpianto(Impianto* imp) {
    impianti.push_back(imp);
    return imp;
}

Impianto* Serra::rimuoviImpianto(int id) {
    Impianto* temp = impianti.at(id);
    impianti.erase(impianti.begin() + id);
    return temp;
}

void Serra::aggiornaImpianti(int hour, int minute) {
    time.AdvanceTime(hour, minute, impianti);
}

void Serra::stampaStatoTutti(){
    for(auto i : impianti) {
        i->Stampa();
    }
}

void Serra::stampaStato(int id){
    for(auto i : impianti) {
        if(id==i->getId()) {
            i->Stampa();
            return;
        }
    }
}

void Serra::attivaImpianto(int id) {
    for(auto i : impianti) {
        if(id==i->getId()) {
            i->Attiva();
            return;
        }
    }
}

void Serra::disattivaImpianto(int id) {
    for(auto i : impianti) {
        if(id==i->getId()) {
            i->Disattiva();
            return;
        }
    }
}

