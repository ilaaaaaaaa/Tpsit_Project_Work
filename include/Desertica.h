//
// Created by ilame on 17/05/2025.
//

#ifndef DESERTICA_H
#define DESERTICA_H

#include "Impianto.h"

class Desertica: public Impianto {
public:
    Desertica(int id = 1004, bool mod = true, float frequenza, float temperatura, bool stato = false, time_t ora = time(0));
};

#endif //DESERTICA_H
