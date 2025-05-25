//
// Meggiolaro Ilaria
//

#include <iostream>
#include <string>
#include "..\Tpsit_Project_Work/include/Serra.h"
#include "..\Tpsit_Project_Work/include/Impianto.h"
#include "../include/Time.h"
#include "..\Tpsit_Project_Work/include/CommandParse.h"
#include "..\Tpsit_Project_Work/include/Alpina.h"
#include "..\Tpsit_Project_Work/include/Carnivora.h"
#include "..\Tpsit_Project_Work/include/Desertica.h"
#include "..\Tpsit_Project_Work/include/Mediterranea.h"
#include "..\Tpsit_Project_Work/include/Tropicale.h"

using namespace std;

void printHelp() {
    cout << "Comandi disponibili:\n";
    cout << "  set ${PLANTID} on               - Accende l'impianto manualmente\n";
    cout << "  set ${PLANTID} off              - Spegne l'impianto manualmente\n";
    cout << "  set ${PLANTID} ${START} ${STOP} - Imposta timer accensione e spegnimento (stop solo per manuali)\n";
    cout << "  set ${PLANTID} ${START}        - Imposta solo l'accensione automatica\n";
    cout << "  rm ${PLANTID}                  - Rimuove timer associato all'impianto\n";
    cout << "  show                          - Mostra tutti gli impianti con stato e consumo\n";
    cout << "  show ${PLANTID}               - Mostra stato e dettagli di un singolo impianto\n";
    cout << "  set time HH:MM                - Imposta l'orario corrente\n";
    cout << "  reset time                   - Riporta orario a 00:00 (impianti spenti, timer rimossi)\n";
    cout << "  reset timers                 - Rimuove tutti i timer mantenendo stato impianti\n";
    cout << "  reset all                    - Ripristina condizioni iniziali (orario, timer, impianti)\n";
    cout << "  exit                         - Esce dal programma\n\n";
}

int main() {
    Serra serra;

    serra.aggiungiImpianto(new Alpina(1003, false, 1.0f, 20.0f));
    serra.aggiungiImpianto(new Carnivora(1005, false, 1.5f, 22.0f));
    serra.aggiungiImpianto(new Desertica(1004, true, 2.0f, 25.0f));
    serra.aggiungiImpianto(new Mediterranea(1001, false, 1.0f, 21.0f));
    serra.aggiungiImpianto(new Tropicale(1002, true, 2.5f, 24.0f));

    Time now;

    printHelp();

    cout << "Inserisci un comando (digita 'exit' per uscire):\n";

    string command;
    while (true) {
        cout << "> ";
        getline(cin, command);

        if (command == "exit") {
            cout << "Uscita dal programma.\n";
            break;
        }

        try {
            processCommand(command, now, serra);
            now.AdvanceTime(now.getHour(), now.getMinute(), serra.getImpianti());
        } catch (const exception& e) {
            cerr << "Errore: " << e.what() << endl;
        }
    }

    return 0;
}