#include <iostream>
#include <string>
#include "BankAccount.h"
#include <limits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>


using namespace std;
const string my_string="Cosa desideri fare? 1 per Deposito, 2 per Prelievo, 3 per fare una transazione, 4 per vedere il bilancio, 5 per modificare una transazione 0 per uscire";

int main() {
    BankAccount *bankAccount = new BankAccount();
    int input;
    int value;
    string description;
    int intero_tipo;
    int transactionIndex;
    string saveData;
    const char *path = R"(C:\Users\182913\CLionProjects\Laboratorio\file.txt)";
    ifstream file1(path);
    vector<string> datas;


    if (file1.good()) {
        string line;

        while (std::getline(file1, line)) {
            //controllo della linea
            datas.push_back(line);
        }
        file1.close();

        for (int i = 0; i < datas.size(); i += 3) {
            if (datas[i + 1] == "Entrata") {
                bankAccount->MakeTransaction(stoi(datas[i]), transactionType::Entrata, datas[i + 2]);
            } else {
                bankAccount->MakeTransaction(stoi(datas[i]), transactionType::Uscita, datas[i + 2]);
            }
        }
    }
   std::ofstream file(path);



    do {
        cout
                << my_string << endl;
        // come gestire un input sbagliato, while controlla che cin sia del tipo giusto a input
        while (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input non valido. Inserisci nuovamente: ";
        }

        cout
                << my_string << endl;

// in base ad input, scegliamo cosa fare, il programma viene eseguito fintanto che non si sceglie 0, il caso default viene usato se un numero e errato
        switch (input) {
            case 1:
                cout << "Inserisci l'importo che desideri depositare" << endl;
                cin >> value;
                bankAccount->Deposit(value,"Deposito");
                break;
            case 2:
                cout << "Inserisci l'importo che desideri prelevare" << endl;
                cin >> value;

                bankAccount->Withdrawing(value,"Prelievo");
                break;
            case 3:
                 cout << "Inserisci l'importo della transazione" << endl;
                 cin >> value;
                if(value<0){
                    printf("Inserire un valore positivo\n");
                    break;
                }

                cout << "Se in Entrata digita 0 se in Uscita digita 1" << endl;
                cin >> intero_tipo;
                cout << "Aggiungi una descrizione alla transazione" << endl;
                cin >> description;
                if (intero_tipo == 0) {
                    bankAccount->MakeTransaction(value, transactionType::Entrata, description);
                } else if (intero_tipo == 1) {
                    bankAccount->MakeTransaction(value, transactionType::Uscita, description);
                } else {
                    cout << "Digita un valore corretto" << endl;
                }
                break;
            case 4:
                std::cout << " \n il tuo bilancio e: " << bankAccount->GetBalance() << endl;
                break;
            case 5:
                cout
                        << "Seleziona l'indice della transazione"
                        << endl;
                while (!(cin >> transactionIndex)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input non valido. Inserisci nuovamente: ";
                }

                cout
                        << "Seleziona l'indice della transazione"
                        << endl;
                if (transactionIndex >= 0 && transactionIndex < bankAccount->transactions.size()) {
                    int newamount;
                    string newDesc;
                    cout
                            << "Seleziona l'importo"
                            << endl;
                    while (!(cin >> newamount)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout
                                << "Seleziona l'importo"
                                << endl;
                    }
                    cout << "scrivi la nuova descrizione" << endl;
                    cin >> newDesc;
                    bankAccount->transactions[transactionIndex]->Modify(newamount, newDesc);

                } else {
                    cout << "Indice errato" << endl;
                }
                break;
                // avviene il salvataggio
            case 0:
                for (int i = 0; i < bankAccount->transactions.size(); i++) {
                    ostringstream stream;
                    stream << fixed << setprecision(2) << bankAccount->transactions[i]->getAmount();
                    string str = stream.str();
                    replace(str.begin(), str.end(), '.', ',');
                    saveData += str + "\n";
                    switch (bankAccount->transactions[i]->type) {

                        case Entrata:
                            saveData += "Entrata\n";
                            break;
                        case Uscita:
                            saveData += "Uscita\n";
                            break;
                    }
                    saveData += bankAccount->transactions[i]->getDescription()  + " in data: " +bankAccount->transactions[i]->data;
                }

                file << saveData;
                file.close();
                break;

            default:
                cout << "hai inserito un numero sbagliato " << endl;
                break;
        }

        }
        while (input != 0);
    }