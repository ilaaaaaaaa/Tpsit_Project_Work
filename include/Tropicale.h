//
// Meggiolaro Ilaria
//

#ifndef TROPICALE_H
#define TROPICALE_H

#include "Impianto.h"

class Tropicale : public Impianto {
public:
    //Costruttore
    Tropicale(float temperatura,
          int id = 1002, bool mod = true, float frequenza = 2.5f, bool stato = false,
          int hour = 0, int minute = 0,
          int ahour = 0, int aminute = 0,
          int shour = 0, int sminute = 0);
};

#endif // TROPICALE_H
