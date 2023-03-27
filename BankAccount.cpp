//
// Created by 182913 on 27/03/2023.
//

#include "BankAccount.h"

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

float BankAccount::getBalance() const {
    float balance = 0.0f;
    for (auto& transaction : m_transactions) {
        balance += transaction->getAmount();
    }
    return balance;
}

std::vector<Transaction*> BankAccount::getTransactions() const {
    return m_transactions;
}