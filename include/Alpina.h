//
// Rossi Samuele
//

#ifndef ALPINA_H
#define ALPINA_H

#include "Impianto.h"

class Alpina : public Impianto {
public:
    //Costruttore
    Alpina(float temperatura, int id = 1003, bool mod = false, float frequenza = 1.0f, bool stato = false,
       int hour = 0, int minute = 0,
       int ahour = 0, int aminute = 0,
       int shour = 0, int sminute = 0);
};

#endif //ALPINA_H

