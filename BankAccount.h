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
    const vector<Transaction*>& GetTransactions() const;
    float GetBalance();
    void SetBalance(float newBalance);
    void MakeTransaction(float amount, transactionType type, string desc);
    void Deposit(float amount, string desc);
    void Withdrawing(float amount, string desc);
private:
    float balance;
    string name;
    vector<Transaction*> transactions;
};

#endif //TRANSAZIONI_ACCOUNT_H
