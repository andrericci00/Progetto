using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include "Transaction.h"
#include "Transaction_in.h"
#include "Transaction_out.h"

//esempio utilizzo classi
int main() {
    std::vector<Transaction *> transazioni;
    ifstream file("transazioni.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            string tipo;
            getline(file, tipo);
            if (tipo == "Entrata") {
                Transaction_in *t = new Transaction_in();
                t->load(file);
                transazioni.push_back(t);
            } else if (tipo == "Uscita") {
                Transaction_out *t = new Transaction_out();
                t->load(file);
                transazioni.push_back(t);
            }
        }
        file.close();
    } else {
        cerr << "Errore durante l'apertura del file di input" << endl;
        return 1;
    }

    int scelta;
    do {
        cout << "1. Aggiungi transazione" << endl;
        cout << "2. Modifica transazione" << endl;
        cout << "3. Elimina transazione" << endl;
        cout << "4. Visualizza transazioni" << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: {
                string tipo;
                cout << "Tipo di transazione (Entrata/Uscita): ";
                cin >> tipo;
                float importo;
                cout << "Importo: ";
                cin >> importo;
                string descrizione;
                cout << "Descrizione: ";
                cin.ignore();
                getline(cin, descrizione);
                if (tipo == "Entrata") {
                    Transaction_in *t = new Transaction_in(importo, descrizione);
                    transazioni.push_back(t);
                } else if (tipo == "Uscita") {
                    Transaction_out *t = new Transaction_out(importo, descrizione);
                    transazioni.push_back(t);
                } else {
                    cout << "Tipo di transazione non valido" << endl;
                }
                break;
            }
            case 2: {
                int index;
                cout << "Indice della transazione da modificare: ";
                cin >> index;
                if (index >= 0 && index < transazioni.size()) {
                    float importo;
                    cout << "Nuovo importo: ";
                    cin >> importo;
                    string descrizione;
                    cout << "Nuova descrizione: ";
                    cin.ignore();
                    getline(cin, descrizione);
                    Transaction *t = transazioni[index];
                    t->m_money = importo;
                    t->m_description = descrizione;
                    cout << "Transazione modificata" << endl;
                } else {
                    cout << "Indice non valido" << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "Indice della transazione da eliminare: ";
                cin >> index;
                if (index >= 0 && index < transazioni.size()) {
                    Transaction *t = transazioni[index];
                    transazioni.erase(transazioni.begin() + index);
                    delete t;
                    cout << "Transazione eliminata" << endl;
                } else {
                    cout << "Indice non valido" << endl;
                }
                break;
            }
            case 4:
                // Visualizza le transazioni
                std::cout << "Transazioni:" << std::endl;
                for (auto &t: transazioni) {
                    std::cout << t->getType() << " di " << t->getAmount() << " euro (" << t->getDescription() << ")"
                              << std::endl;
                }
                break;
            case 0:
                std::cout << "Uscita dal programma" << std::endl;
                break;
            default:
                std::cout << "Scelta non valida" << std::endl;
                break;
        }
    } while (scelta != 0);

// Salva le transazioni sul file di output
    ofstream outFile("transazioni_output.txt");
    if (outFile.is_open()) {
        for (auto &t: transazioni) {
            t->save(outFile);
            outFile << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Errore durante l'apertura del file di output" << std::endl;
        return 1;
    }

// Deallocazione della memoria
    for (auto &t: transazioni) {
        delete t;
    }
    return 0;
}
