//
// Munaro Alex - Meggiolaro Ilaria
//

#include "../include/Serra.h"
#include "../include/Impianto.h"

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

void Serra::aggiornaImpianti(int orario) {

}

void Serra::stampaStatoTutti(){
    //for (const auto& [id, impianto] : impianti) {
      //  std::cout << "Impianto ID " << id << ": ";
        //impianto->stampaStato();
    //}
}
