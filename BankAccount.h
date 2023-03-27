//
// Created by 182913 on 27/03/2023.
//

#ifndef LABORATORIO_BANKACCOUNT_H
#define LABORATORIO_BANKACCOUNT_H


#include <string>
#include <vector>
#include "Transaction.h"

class BankAccount {
public:
    BankAccount(const std::string& owner);

    void addTransaction(Transaction* transaction);
    void removeTransaction(int index);
    float getBalance() const;
    std::vector<Transaction*> getTransactions() const;

private:
    std::string m_owner;
    std::vector<Transaction*> m_transactions;
};

#endif //LABORATORIO_BANKACCOUNT_H
