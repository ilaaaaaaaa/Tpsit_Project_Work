//
// Created by ilame on 17/05/2025.
//

#ifndef MEDITERRANEA_H
#define MEDITERRANEA_H

#include "Impianto.h"
#include <random>

using namespace std;

class Mediterranea : public Impianto {
public:
    Mediterranea(int id = 1001, bool mod = false, float frequenza = 1.0f, bool stato = false, time_t ora = time(0));
    void aggiornaTemperatura();
};

#endif //MEDITERRANEA_H
