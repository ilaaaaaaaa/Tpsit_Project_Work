//
// Meggiolaro Ilaria
//

#ifndef MEDITERRANEA_H
#define MEDITERRANEA_H

#include "Impianto.h"

class Mediterranea : public Impianto {
public:
    Mediterranea(int id = 1001, bool mod = false, float frequenza = 1.0f, bool stato = false,
                 int hour = 0, int minute = 0,
                 int ahour = 0, int aminute = 0,
                 int shour = 0, int sminute = 0);

    void aggiornaTemperatura();
};

#endif // MEDITERRANEA_H
