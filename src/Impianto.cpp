//
// Created by ilame on 10/05/2025.
//

#include "../include/Impianto.h"

Impianto::Impianto(int id, bool mod, float frequenza, float temperatura, bool stato, time_t ora): id(id), modalita(mod), frequenza(frequenza), temperatura(temperatura), stato(stato), ora(ora) {}

int Impianto::getId() const {
    return id;
}