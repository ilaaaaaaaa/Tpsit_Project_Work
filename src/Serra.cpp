//
// Created by ilame on 12/05/2025.
//
#include "../include/Serra.h"
#include "../include/Impianto.h"

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

void Serra::stampaStatoTutti() const {
    for (const auto& [id, impianto] : impianti) {
        std::cout << "Impianto ID " << id << ": ";
        impianto->stampaStato();
    }
}

void Serra::attivaAutomatici() {
    for (auto& [id, impianto] : impianti) {
        if (impianto->isAutomatico()) {
            impianto->attiva();
        }
    }
}

std::shared_ptr<Impianto> Serra::getImpianto(int id) const {
    auto it = impianti.find(id);
    return (it != impianti.end()) ? it->second : nullptr;
}