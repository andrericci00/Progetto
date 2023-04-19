//
// Created by 182913 on 27/03/2023.
//
#include <cmath>
#include "BankAccount.h"


float BankAccount::GetBalance() {
    return balance;
}

void BankAccount::Withdrawing(float amount  ) {
    balance-= amount;
    balance = std::round(balance*100)/100;
}
void BankAccount::Deposit(float amount) {
    balance+=amount;
    balance = std::round(balance*100)/100;
}
void BankAccount::MakeTransaction(float amount,transactionType type, string desc ) {
    Transaction* t= new Transaction(amount, type, desc);
    transactions.push_back(t);
    switch (type) {
        case Entrata:
            BankAccount::Deposit(amount);
            break;
        case Uscita:
            BankAccount::Withdrawing(amount);
            break;
    }
}