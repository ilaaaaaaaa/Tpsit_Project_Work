//
// Meggiolaro Ilaria
//

#ifndef DESERTICA_H
#define DESERTICA_H

#include "Impianto.h"

class Desertica: public Impianto {
public:
    //Costruttore
    Desertica(float temperatura,
          int id = 1004, bool mod = true, float frequenza = 2.0f, bool stato = false,
          int hour = 0, int minute = 0,
          int ahour = 0, int aminute = 0,
          int shour = 0, int sminute = 0);
};

#endif //DESERTICA_H

