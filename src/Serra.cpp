//
// Munaro Alex
//

#include "../include/Serra.h"
#include "../include/Impianto.h"
#include "../include/Time.h"

#include <iostream>

using namespace std;

Serra::~Serra() {
    for (auto imp : impianti) {
        delete imp;
    }
    impianti.clear();
}

//Metodo per l'aggiunta di un impianto (Serra assume la proprietà del puntatore)
Impianto* Serra::aggiungiImpianto(Impianto* imp) {
    impianti.push_back(imp);
    return imp;
}

//Metodo per la rimozione di un impianto dato un id
Impianto* Serra::rimuoviImpianto(int id) {
    Impianto* temp = impianti.at(id);
    impianti.erase(impianti.begin() + id);
    return temp;
}

//Metodo per l'aggiornamento di tutti gli impianti
void Serra::aggiornaImpianti(int hour, int minute) {
    time.AdvanceTime(hour, minute, impianti);
}

//Metodo per la stampa dello stato di tutti gli impianti
void Serra::stampaStatoTutti(){
    for(auto i : impianti) {
        i->Stampa();
    }
}

//Metodo per la stampa dello stato di un impianto dato il proprio id
void Serra::stampaStato(int id){
    for(auto i : impianti) {
        if(id==i->getId()) {
            i->Stampa();
            return;
        }
    }
}

//Metodo per attivare un impianto specifico per id
void Serra::attivaImpianto(int id) {
    for(auto i : impianti) {
        if(id==i->getId()) {
            i->Attiva();
            return;
        }
    }
}

//Metodo per disattivare un impianto specifico per id
void Serra::disattivaImpianto(int id) {
    for(auto i : impianti) {
        if(id==i->getId()) {
            i->Disattiva();
            return;
        }
    }
}

