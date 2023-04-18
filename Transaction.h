//
// Created by 182913 on 06/03/2023.
//

#include <string>

#ifndef TRANSAZIONI_TRANSACTION_H
#define TRANSAZIONI_TRANSACTION_H
enum transactionType{
    Entrata,
    Uscita
};

using namespace std;

class Transaction {
public:

    float amount;
    transactionType type;
    string description;
    Transaction(float amount, transactionType type1, string description);
    void Modify(float num,string desc);
};


#endif //TRANSAZIONI_TRANSACTION_H