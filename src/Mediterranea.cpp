//
// Meggiolaro Ilaria
//

#include "../include/Mediterranea.h"
#include <iostream>

using namespace std;

//Costruttore
Mediterranea::Mediterranea(int id, bool mod, float frequenza, bool stato,
                           int hour, int minute,
                           int ahour, int aminute,
                           int shour, int sminute)
: Impianto(id, mod, frequenza, 28.0f, stato, hour, minute, ahour, aminute, shour, sminute)
{}

//Metodo per l'aggiornamento della temperatura
void Mediterranea::aggiornaTemperatura() {
    static bool randomInitialized = false;
    if (!randomInitialized) {
        srand(time(nullptr));
        randomInitialized = true;
    }

    float temp = temperatura;

    if (!stato) {
        //Random tra 0.01 e 0.05
        float r = rand() % 5 + 1;      //1-5
        float decremento = r / 100.0f;      //0.01-0.05
        temp -= decremento;
        cout << "Impianto spento. Temperatura scesa a " << temp << "°C\n";

        if (temp < 25.0f) {
            stato = true;
            cout << "Temperatura troppo bassa. Impianto acceso.\n";
        }
    } else {
        //Random tra 0.75 e 1.0
        float r = rand() % 26 + 75;    //75-100
        float incremento = r / 100.0f;      //0.75-1.0
        temp += incremento;
        if (temp > 28.0f) temp = 28.0f;
        cout << "Impianto acceso. Temperatura aumentata a " << temp << "°C\n";
    }

    temperatura = temp;
}
