//
// Created by ilame on 17/05/2025.
//

#ifndef CARNIVORA_H
#define CARNIVORA_H

#include "Impianto.h"

class Carnivora: public Impianto {
public:
    Carnivora(int id = 1005, bool mod = false, float frequenza = 1.5f, float temperatura, bool stato = false, time_t ora = time(0));
};


#endif //CARNIVORA_H
