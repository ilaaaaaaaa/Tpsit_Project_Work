//
// Munaro Alex
//

#ifndef SERRA_H
#define SERRA_H

#include <vector>
#include "../include/Impianto.h" //Classe base astratta degli impianti
#include "../include/Time.h"

using namespace std;

class Serra {
private:
    vector<Impianto*> impianti; //Array di impianti passati per riferimento
    Time time;
public:
    //Costruttore e distruttore
    Serra() = default;

    ~Serra();

    //Metodo per l'aggiunta di un impianto (Serra assume la proprietà del puntatore)
    Impianto* aggiungiImpianto(Impianto* impianto);

    //Metodo per la rimozione di un impianto dato un id
    Impianto* rimuoviImpianto(int id);

    //Metodo per l'aggiornamento di tutti gli impianti
    void aggiornaImpianti(int hour, int minute);

    //Metodo per la stampa dello stato di tutti gli impianti
    void stampaStatoTutti();

    //Metodo per la stampa dello stato di un impianto dato il proprio id
    void stampaStato(int id);

    //Metodo per attivare un impianto specifico per id
    void attivaImpianto(int id);

    //Metodo per disattivare un impianto specifico per id
    void disattivaImpianto(int id);

    //Metodo che ritorna il vettore contenente tutti gli impianti
    vector<Impianto*>& getImpianti() { return impianti; }
};

#endif // SERRA_H