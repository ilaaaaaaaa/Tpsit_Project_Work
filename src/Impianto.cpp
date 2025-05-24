//
// Created by ilame on 10/05/2025.
//
#include <iostream>
#include "../include/Impianto.h"

Impianto::Impianto(int id, bool mod, float frequenza, float temperatura, bool stato, int hour, int minute, int ahour, int aminute, int shour, int sminute): id(id), modalita(mod), frequenza(frequenza), temperatura(temperatura), stato(stato), IHour(hour), IMinute(minute), AHour(ahour), AMinute(aminute), SHour(shour), SMinute(sminute){}

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

void Impianto::Automatica(){
    if(modalita) {
        stato = !stato;
        if(stato)
            std::cout << "L'impianto " << id << "è acceso" << std::endl;
        else
            std::cout << "L'impianto " << id << "è spento" << std::endl;
    }
}