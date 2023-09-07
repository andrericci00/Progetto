//
// Created by 182913 on 27/03/2023.
//
#include <cmath>
#include <stdexcept>
#include "BankAccount.h"



float BankAccount::GetBalance() {
    balance=0;
    for(int i=0; i<transactions.size(); i++) {
        if(transactions[i]->type==transactionType::Entrata){
            balance+=transactions[i]->getAmount();
        }
        else{
            balance-=transactions[i]->getAmount();
        }

    }
    return balance;
}

void BankAccount::Withdrawing(float amount, string desc) {
    if (amount < 0) {
        printf("Inserisci un numero positivo\n");
        // Aggiungi qui la gestione dell'errore se l'importo è negativo, ad esempio un'eccezione.
    } else if (amount > balance) {
        printf("Non hai abbastanza fondi");
    } else {
        Transaction *t = new Transaction(amount, transactionType::Uscita, desc);
        transactions.push_back(t);
        // Aggiorna il saldo dopo il prelievo
        balance -= amount;
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
            case transactionType::Entrata:
                BankAccount::Deposit(amount, desc);
                break;
            case transactionType::Uscita:
                BankAccount::Withdrawing(amount, desc);
                break;
        }
    }

