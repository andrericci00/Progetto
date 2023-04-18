//
// Created by 182913 on 06/03/2023.
//

#include "Transaction.h"
Transaction::Transaction(float amount, transactionType type1, string description) {
    this->amount=amount;
    this->type=type1;
    this->description=description;
}

void Transaction::Modify(float num,string desc) {
    amount=num;
    description=desc;
}