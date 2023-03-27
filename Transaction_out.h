//
// Created by 182913 on 06/03/2023.
//

#ifndef LABORATORIO_TRANSACTION_OUT_H
#define LABORATORIO_TRANSACTION_OUT_H


#include "Transaction.h"

class Transaction_out : public Transaction {
public:
    Transaction_out();
    Transaction_out(float amount, const string& description) : Transaction(amount,description){}

    virtual string getType() const override {
        return "Uscita";
    }

    void save(ofstream& file) const override {
        file << getType() << endl;
        file << getAmount() << endl;
        file << getDescription() << endl;
    }
    void load(ifstream& file) override {
        string type, description;
        float amount;
        getline(file,type);
        file >> amount;
        file.ignore();
        getline(file,description);
        *this = Transaction_out(amount,description);
    }

    float m_money;
};

#endif //LABORATORIO_TRANSACTION_OUT_H
