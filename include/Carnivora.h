//
// Rossi Samuele
//

#ifndef CARNIVORA_H
#define CARNIVORA_H

#include "Impianto.h"

class Carnivora: public Impianto {
public:
    //Costruttore
    Carnivora(float temperatura,
          int id = 1005, bool mod = false, float frequenza = 1.5f, bool stato = false,
          int hour = 0, int minute = 0,
          int ahour = 0, int aminute = 0,
          int shour = 0, int sminute = 0);
};

#endif //CARNIVORA_H

