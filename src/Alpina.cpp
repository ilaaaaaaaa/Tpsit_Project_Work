//
// Rossi Samuele
//

#include "../include/Alpina.h"

//Costruttore
Alpina::Alpina(float temperatura, int id, bool mod, float frequenza, bool stato,
               int hour, int minute,
               int ahour, int aminute,
               int shour, int sminute)
: Impianto(id, mod, frequenza, temperatura, stato, hour, minute, ahour, aminute, shour, sminute){}