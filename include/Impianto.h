//
// Created by ilame on 10/05/2025.
//

#ifndef IMPIANTO_H
#define IMPIANTO_H
#include <ctime>

class Impianto {
private:
    int id;
    bool modalità;
    float frequenza;
    bool stato;
    time_t ora;

public:
    explicit Impianto(int id, bool mod, float frequenza, bool stato, time_t ora);
    int getId() const;
};


#endif //IMPIANTO_H
