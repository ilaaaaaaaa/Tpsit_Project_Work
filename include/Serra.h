//
// Munaro Alex
//

#ifndef SERRA_H
#define SERRA_H

#include <vector>
#include "../include/Impianto.h" // Classe base astratta degli impianti
#include "../include/Time.h"
class Serra {
private:
    std::vector<Impianto*> impianti;
    Time time;
public:
    // Costruttore e distruttore
    Serra() = default;

    ~Serra();

    // Aggiunge un impianto (Serra assume la proprietà del puntatore)
    Impianto* aggiungiImpianto(Impianto* impianto);

    // Rimuove un impianto dato un id
    Impianto* rimuoviImpianto(int id);

    // Esegue l'aggiornamento di tutti gli impianti
    void aggiornaImpianti(int hour, int minute);

    // Stampa lo stato di tutti gli impianti
    void stampaStatoTutti();

    void stampaStato(int id);
    // Attiva/disattiva un impianto specifico per id
    void attivaImpianto(int id);
    void disattivaImpianto(int id);

    // Ottiene un impianto per id (const)
};

#endif // SERRA_H