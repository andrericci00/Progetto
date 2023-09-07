//
// Created by 182913 on 06/03/2023.
//

#include <stdexcept>
#include "Transaction.h"
Transaction::Transaction(float amount, transactionType type1, string description) {
    if (amount < 0.0) {
        throw std::invalid_argument("L'importo deve essere positivo.");
    }

    this->amount = amount;
    this->type = type1;
    this->description = description;
}


void Transaction::Modify(float num,string desc) {
    amount=num;
    description=desc;
}

void Transaction::setAmount(float amount) {
    Transaction::amount = amount;
}
int Transaction::getAmount() const {
    return amount;
}

void Transaction::setDescription(string description) {
    Transaction::description = description;
}

string Transaction::getDescription() const {
    return description;
}