//
// Created by 182913 on 27/03/2023.
//

#include "BankAccount.h"
#include "Transaction_in.h"
#include "Transaction_out.h"

BankAccount::BankAccount(const std::string& owner) : m_owner(owner) {}

void BankAccount::addTransaction(Transaction* transaction) {
    m_transactions.push_back(transaction);
}


void BankAccount::removeTransaction(int index) {
    if (index >= 0 && index < m_transactions.size()) {
        delete m_transactions[index];
        m_transactions.erase(m_transactions.begin() + index);
    }
}

float BankAccount::getBalance()  {
    float balance = 0.0f;
    for (auto& transaction : m_transactions) {
        if (transaction->getType() == "Entrata") {
            balance += transaction->getAmount();
        } else {
            balance -= transaction->getAmount();
        }
    }
    return balance;

}
void BankAccount::deposit(float amount) {
    Transaction* transaction = new Transaction_in(amount, "Deposito");
    addTransaction(transaction);
}
void BankAccount::prelievo(float amount) {
    Transaction* transaction = new Transaction_out(amount, "Prelievo");
    addTransaction(transaction);
}

std::vector<Transaction*> BankAccount::getTransactions() const {
    return m_transactions;
}