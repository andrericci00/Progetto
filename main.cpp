using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include "Transaction.h"

#include "BankAccount.h"

//esempio utilizzo classi
int main() {
    BankAccount bankaccount("Luca Rossi");
    std::vector<Transaction *> transactions;
    ifstream file("transazioni.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            string type;
            getline(file, type);
            if (type == "Entrata") {
                Transaction_in *t = new Transaction_in();
                t->load(file);
                transactions.push_back(t);
            } else if (type == "Uscita") {
                Transaction_out *t = new Transaction_out();
                t->load(file);
                transactions.push_back(t);
            }
        }
        file.close();
    } else {
        cerr << "Errore durante l'apertura del file di input" << endl;
        return 1;
    }



    int choice;
    do {
        cout << "1. Aggiungi transazione" << endl;
        cout << "2. Modifica transazione" << endl;
        cout << "3. Elimina transazione" << endl;
        cout << "4. Visualizza transazioni" << endl;
        cout << "5. Visualizza saldo" << endl;
        cout << "0. Esci" << endl;
        cout << "Scelta: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string type;
                cout << "Tipo di transazione (Entrata/Uscita): ";
                cin >> type;
                float amount;
                cout << "Importo: ";
                cin >> amount;
                string description;
                cout << "Descrizione: ";
                cin.ignore();
                getline(cin, description);
                if (type == "Entrata") {
                    Transaction_in *t = new Transaction_in(amount, description);
                    transactions.push_back(t);
                    bankaccount.deposit(amount);
                } else if (type == "Uscita") {
                    Transaction_out *t = new Transaction_out(amount, description);
                    transactions.push_back(t);
                    bankaccount.prelievo(amount);
                } else {
                    cout << "Tipo di transazione non valido" << endl;
                }
                break;
            }
            case 2: {
                int index;
                cout << "Indice della transazione da modificare: ";
                cin >> index;
                if (index >= 0 && index < transactions.size()) {
                    float amount;
                    cout << "Nuovo importo: ";
                    cin >> amount;
                    string description;
                    cout << "Nuova descrizione: ";
                    cin.ignore();
                    getline(cin, description);
                    Transaction *t = transactions[index];
                    t->m_money = amount;
                    t->m_description = description;
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
                if (index >= 0 && index < transactions.size()) {
                    Transaction *t = transactions[index];
                    transactions.erase(transactions.begin() + index);
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
                for (auto &t: transactions) {
                    std::cout << t->getType() << " di " << t->getAmount() << " euro (" << t->getDescription() << ")"
                              << std::endl;
                }
                break;
            case 5: {
                cout << "Saldo: " << bankaccount.getBalance() << endl;
                break;
            }
            case 0:
                std::cout << "Uscita dal programma" << std::endl;
                break;
            default:
                std::cout << "Scelta non valida" << std::endl;
                break;
        }
    } while (choice != 0);

// Salva le transazioni sul file di output
    ofstream outFile("transazioni.txt");
    if (outFile.is_open()) {
        for (auto &t: transactions) {
            t->save(outFile);
            outFile << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Errore durante l'apertura del file di output" << std::endl;
        return 1;
    }

// Deallocazione della memoria
    for (auto &t: transactions) {
        delete t;
    }
    return 0;
}
