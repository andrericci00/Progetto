//
// Created by 182913 on 06/03/2023.
//

#include "Transaction.h"
#include <iostream>
Transaction::Transaction(): m_money(0) , m_description("") {}
Transaction::Transaction(float importo, const string& description) : m_money(importo), m_description(description) {}

float Transaction::getImporto() const {
    return m_money;
}

string Transaction::getDescription() const {
    return m_description;
}