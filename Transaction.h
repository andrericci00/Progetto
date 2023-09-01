//
// Created by 182913 on 06/03/2023.
//

#include <string>
#include <vector>
#include <ctime>

#ifndef TRANSAZIONI_TRANSACTION_H
#define TRANSAZIONI_TRANSACTION_H
enum transactionType{
    Entrata,
    Uscita
};

using namespace std;

class Transaction {
public:
    Transaction(float amount, transactionType type1, string description);
    void Modify(float num,string desc);
    void setAmount(float amount);
    time_t now = time(0);
    string data = ctime(&now);
    int getAmount();
    transactionType type;
    void setDescription(string description);
    string getDescription();
private:
    float amount;
    string description;



};



#endif //TRANSAZIONI_TRANSACTION_H