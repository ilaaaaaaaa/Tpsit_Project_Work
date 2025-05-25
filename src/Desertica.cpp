//
// Meggiolaro Ilaria
//

#include "../include/Desertica.h"

Desertica::Desertica(int id, bool mod, float frequenza, float temperatura, bool stato,
                     int hour, int minute,
                     int ahour, int aminute,
                     int shour, int sminute)
    : Impianto(id, mod, frequenza, temperatura, stato, hour, minute, ahour, aminute, shour, sminute) {}
