//
// Created by ilame on 10/05/2025.
//

#ifndef IMPIANTO_H
#define IMPIANTO_H

#include <ctime>

class Impianto {
protected:
    int id;
    bool modalita;
    float frequenza;
    float temperatura;
    bool stato;
    time_t ora;

public:
    Impianto(int id, bool mod, float frequenza, float temperatura, bool stato, time_t ora);
    int getId() const;
};




#endif //IMPIANTO_H
