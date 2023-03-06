using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include "Transaction.h"
#include "Transaction_in.h"
#include "Transaction_out.h"

//esempio utilizzo classi
int main() {
    std::vector<Transaction*> transazioni;
    transazioni.push_back(new Transaction_in(100.0, "Stipendio"));
    transazioni.push_back(new Transaction_out(50.0, "Spesa al supermercato"));
    transazioni.push_back(new Transaction_out(20.0, "Benzina"));

    std::ofstream file("transazioni.txt");
    if (!file) {
        std::cerr << "Errore durante l'apertura del file di output" << std::endl;
        return 1;
    }

    for (auto t : transazioni) {
        t->save(file);
    }

    file.close();

    for (auto t : transazioni) {
        delete t;
    }

    return 0;
}



