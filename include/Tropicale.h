//
// Created by ilame on 17/05/2025.
//

#ifndef TROPICALE_H
#define TROPICALE_H

#include "Impianto.h"

class Tropicale : public Impianto {
public:
    Tropicale(int id = 1002, bool mod = true, float frequenza = 2.5f, bool stato = false, time_t ora = time(0));
};

#endif //TROPICALE_H
