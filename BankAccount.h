//
// Created by 182913 on 27/03/2023.
//

#include <string>
#include <vector>
#include "Transaction.h";
#ifndef TRANSAZIONI_ACCOUNT_H
#define TRANSAZIONI_ACCOUNT_H
using namespace std;

class BankAccount {

public:
    float balance;
    string name;
    vector<Transaction*> transactions;
    float GetBalance();
    void MakeTransaction(float amount, transactionType type, string desc);
    void Deposit(float amount);
    void Withdrawing(float amount);


};

#endif //TRANSAZIONI_ACCOUNT_H
