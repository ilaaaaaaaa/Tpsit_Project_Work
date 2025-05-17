//
// Created by ilame on 17/05/2025.
//

#include "../include/Mediterranea.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Mediterranea::Mediterranea(int id, bool mod, float frequenza, bool stato, time_t ora): Impianto(id, mod, frequenza, 28.0f, stato, ora) {
    srand(time(0)); //inizializza la casualità
}

void Mediterranea::aggiornaTemperatura() {
    float temp = temperatura;

    if (!stato) {
        //Random tra 0.01 e 0.05
        float r = rand() % 5 + 1;    //Numero intero tra 1 e 5
        float decremento = r / 100;  //Valore tra 0.01 e 0.05
        temp -= decremento;
        cout << "Impianto spento. Temperatura scesa a " << temp << "°C\n";

        if (temp < 25.0f) {
            stato = true;
            cout << "Temperatura troppo bassa. Impianto acceso.\n";
        }
    } else {
        // Random tra 0.75 e 1.0
        float r = rand() % 26 + 75;      //Numero intero tra 75 e 100
        float incremento = r / 100.0f;   //Valore float tra 0.75 e 1.00
        temp += incremento;
        if (temp > 28.0f) temp = 28.0f;
        cout << "Impianto acceso. Temperatura aumentata a " << temp << "°C\n";
    }

    temperatura = temp;
}


