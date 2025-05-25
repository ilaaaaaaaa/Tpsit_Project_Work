//
// Meggiolaro Ilaria
//

#include "..\include\CommandParse.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

Time now; //Variabile globale simulata per l’orario corrente

void logMessage(const Time& time, const string& message, const int& errorLevel) {
    if (errorLevel == 0)
        cout << "[" << time.toString() << "]\t" << message << endl;
    else if (errorLevel == 1)
        cerr << "[" << time.toString() << "]\t" << message << endl;
}

vector<string> commandParser(const string& command) {
    vector<string> tokens;
    istringstream ss(command);
    string token;

    bool isDeviceName = false;
    string deviceName;

    while (ss >> token) {
        if (isDeviceName) {
            if (token == "on" || token == "off" || token.find(':') != string::npos) {
                if (!deviceName.empty()) {
                    tokens.push_back(deviceName);
                    deviceName.clear();
                }
                isDeviceName = false;
            }
        }

        if (token == "set" || token == "rm" || token == "show") {
            tokens.push_back(token);
            isDeviceName = true;
            continue;
        }

        if (isDeviceName) {
            if (!deviceName.empty()) {
                deviceName += " ";
            }
            deviceName += token;
        } else {
            tokens.push_back(token);
        }
    }

    if (!deviceName.empty()) {
        tokens.push_back(deviceName);
    }

    return tokens;
}

void processCommand(const string& command) {
    logMessage(now, "L'orario attuale è " + now.toString(), 0);
    vector<string> tokens = commandParser(command);

    if (tokens.empty()) {
        throw invalid_argument("Errore: comando vuoto.");
    }

    const string& action = tokens[0];

    if (action == "set") {
        if (tokens.size() < 2) {
            throw invalid_argument("Errore: comando 'set' incompleto.");
        }

        const string& deviceName = tokens[1];

        if (deviceName == "time") {
            if (tokens.size() != 3) {
                throw invalid_argument("Errore: formato per 'set time' non valido. Usa: set time HH:MM");
            }
            Time time;
            time.setFromString(tokens[2]);
            now = time;
        } else {
            if (tokens.size() < 3) {
                throw invalid_argument("Errore: comando 'set' incompleto per dispositivo.");
            }

            const string& operation = tokens[2];

            if (operation == "on") {
                // accendi dispositivo
            } else if (operation == "off") {
                // spegni dispositivo
            } else {
                Time start;
                start.setFromString(operation);
                if (tokens.size() == 4) {
                    Time stop;
                    stop.setFromString(tokens[3]);
                    // imposta timer start e stop per deviceName
                } else {
                    // imposta timer start per deviceName
                }
            }
        }

    } else if (action == "rm") {
        if (tokens.size() != 2) {
            throw invalid_argument("Errore: comando 'rm' non valido. Usa: rm ${DEVICENAME}");
        }
        // rimuovi timer da deviceName

    } else if (action == "show") {
        if (tokens.size() == 1) {
            // mostra tutti i dispositivi
        } else if (tokens.size() == 2) {
            // mostra singolo dispositivo
        } else {
            throw invalid_argument("Errore: comando 'show' non valido. Usa: show oppure show ${DEVICENAME}");
        }

    } else if (action == "reset") {
        if (tokens.size() != 2) {
            throw invalid_argument("Errore: comando 'reset' non valido.");
        }

        const string& resetType = tokens[1];
        if (resetType == "time") {
            // resetta orario
        } else if (resetType == "timers") {
            // resetta tutti i timer
        } else if (resetType == "all") {
            // resetta orario e timer
        } else {
            throw invalid_argument("Errore: opzione 'reset' non valida. Usa: reset time | reset timers | reset all");
        }

    } else {
        throw invalid_argument("Errore: comando '" + action + "' non riconosciuto.");
    }
}
