//
// Meggiolaro Ilaria
//

#include "../include/CommandParse.h"
#include "../include/Time.h"
#include "../include/Serra.h"
#include "../include/Impianto.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// Funzione di logging con orario
void logMessage(const Time& time, const string& message, const int& errorLevel) {
    if (errorLevel == 0)
        cout << "[" << time.toString() << "]\t" << message << endl;
    else if (errorLevel == 1)
        cerr << "[" << time.toString() << "]\t" << message << endl;
}

// Parsing del comando in token
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

// Funzione principale per il processamento dei comandi
void processCommand(const string& command, Time& now, Serra& serra) {
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
            now.setFromString(tokens[2]);

        } else {
            if (tokens.size() < 3) {
                throw invalid_argument("Errore: comando 'set' incompleto per dispositivo.");
            }

            const string& operation = tokens[2];

            try {
                int id = stoi(deviceName);

                if (operation == "on") {
                    serra.attivaImpianto(id);

                } else if (operation == "off") {
                    serra.disattivaImpianto(id);

                } else {
                    Time start, stop;
                    start.setFromString(operation);

                    if (tokens.size() == 4) {
                        stop.setFromString(tokens[3]);
                        for (auto imp : serra.getImpianti()) {
                            if (imp->getId() == id) {
                                imp->setStart(start);
                                imp->setStop(stop);
                                break;
                            }
                        }
                    } else {
                        for (auto imp : serra.getImpianti()) {
                            if (imp->getId() == id) {
                                imp->setStart(start);
                                break;
                            }
                        }
                    }
                }

            } catch (...) {
                throw invalid_argument("Errore: ID dispositivo non valido.");
            }
        }

    } else if (action == "rm") {
        if (tokens.size() != 2) {
            throw invalid_argument("Errore: comando 'rm' non valido. Usa: rm ${ID}");
        }

        try {
            int id = stoi(tokens[1]);
            for (auto imp : serra.getImpianti()) {
                if (imp->getId() == id) {
                    Time zero;
                    zero.SetTime(0, 0);
                    imp->setStart(zero);
                    imp->setStop(zero);
                    logMessage(now, "Timer rimosso da impianto " + to_string(id), 0);
                    break;
                }
            }

        } catch (...) {
            throw invalid_argument("Errore: ID non valido.");
        }

    } else if (action == "show") {
        if (tokens.size() == 1) {
            serra.stampaStatoTutti();

        } else if (tokens.size() == 2) {
            try {
                int id = stoi(tokens[1]);
                serra.stampaStato(id);
            } catch (...) {
                throw invalid_argument("Errore: ID dispositivo non valido.");
            }

        } else {
            throw invalid_argument("Errore: comando 'show' non valido. Usa: show oppure show ${ID}");
        }

    } else if (action == "reset") {
        if (tokens.size() != 2) {
            throw invalid_argument("Errore: comando 'reset' non valido.");
        }

        const string& resetType = tokens[1];
        if (resetType == "time") {
            now.SetTime(0, 0);

        } else if (resetType == "timers" || resetType == "all") {
            Time zero;
            zero.SetTime(0, 0);

            for (auto imp : serra.getImpianti()) {
                imp->setStart(zero);
                imp->setStop(zero);
            }

            if (resetType == "all") {
                now.SetTime(0, 0);
            }

        } else {
            throw invalid_argument("Errore: opzione 'reset' non valida. Usa: reset time | reset timers | reset all");
        }

    } else {
        throw invalid_argument("Errore: comando '" + action + "' non riconosciuto.");
    }
}
