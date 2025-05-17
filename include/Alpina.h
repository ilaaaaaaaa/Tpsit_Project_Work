//
// Created by ilame on 17/05/2025.
//

#ifndef ALPINA_H
#define ALPINA_H

#include "Impianto.h"

using namespace std;

class Alpina : public Impianto {
public:
    Alpina(int id = 1003, bool mod = false, float frequenza = 1.0f, float temperatura,bool stato = false, time_t ora = time(0));
};

#endif //ALPINA_H
