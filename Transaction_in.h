//
// Created by 182913 on 06/03/2023.
//

#ifndef LABORATORIO_TRANSACTION_IN_H
#define LABORATORIO_TRANSACTION_IN_H
#include "Transaction.h"

class Transaction_in : public Transaction{
public:
    Transaction_in();
    Transaction_in(float amount, const string& description): Transaction(amount,description){}

    string getType() const override {
        return "Entrata";
    }
    void save(ofstream& file) const override{
        file << getType() << endl;
        file << getAmount() << endl;
        file << getDescription() << endl;
    }
    void load(ifstream& file) override {
        string type, description;
        float amount;
        getline(file, type);
        file >> amount;
        file.ignore();
        getline(file, description);
        *this = Transaction_in(amount,description);
    }

};


#endif //LABORATORIO_TRANSACTION_IN_H
