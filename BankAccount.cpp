//
// Created by 182913 on 27/03/2023.
//
#include <cmath>
#include "BankAccount.h"



float BankAccount::GetBalance() {
    balance=0;
    for(int i=0; i<transactions.size(); i++) {
        if(transactions[i]->type==Entrata){
            balance+=transactions[i]->amount;
        }
        else{
            balance-=transactions[i]->amount;
        }

    }
    return balance;
}

void BankAccount::Withdrawing(float amount, string desc ) {
    if(amount<0){
        printf("Inserisci un numero positivo\n");
    }
    else {
        Transaction *t = new Transaction(amount, transactionType::Uscita, desc);
        transactions.push_back(t);
        //balance-= amount;
        //balance = std::round(balance*100)/100;
    }
}
void BankAccount::Deposit(float amount, string desc) {
    if(amount<0){
        printf("Inserisci un numero positivo\n");
    }
    else {
        Transaction *t = new Transaction(amount, transactionType::Entrata, desc);
        transactions.push_back(t);
    }
    //balance+=amount;
    //balance = std::round(balance*100)/100;
}
void BankAccount::MakeTransaction(float amount,transactionType type, string desc ) {

        switch (type) {
            case Entrata:
                BankAccount::Deposit(amount, desc);
                break;
            case Uscita:
                BankAccount::Withdrawing(amount, desc);
                break;
        }
    }

