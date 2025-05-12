//
// Created by ilame on 10/05/2025.
//

#ifndef IMPIANTO_H
#define IMPIANTO_H
#include <ctime>

class Impianto {
public:
    int id;
    bool modalità;
    float frequenza;
    bool stato;
    time_t ora;
    explicit Impianto(int id, bool mod, float frequenza, bool stato, time_t ora):id{id},modalità{mod},frequenza{frequenza},stato{stato},ora{ora}{}

};


#endif //IMPIANTO_H
