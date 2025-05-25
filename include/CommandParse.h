//
// Meggiolaro Ilaria
//

#ifndef COMMANDPARSE_H
#define COMMANDPARSE_H

#include <string>
#include <vector>
#include "Time.h"

using namespace std;

void logMessage(const Time& time, const string& message, const int& errorLevel);
vector<string> commandParser(const string& command);
void processCommand(const string& command);

#endif //COMMANDPARSE_H
