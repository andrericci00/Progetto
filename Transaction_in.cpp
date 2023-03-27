//
// Created by 182913 on 06/03/2023.

#include "Transaction.h"
#include "Transaction_in.h"

Transaction_in::Transaction_in() : Transaction(){}
Transaction_in::Transaction_in(float amount, const string &description) : Transaction(amount, description), m_money(amount){}
string Transaction_in::getType() const {
    return "Entrata";
}
void Transaction_in::save(ofstream &file) const {
    file << getType() << endl;
    file << m_money << endl;
    file << m_description << endl;
}

void Transaction_in::load(ifstream &file) {
    file >> m_money;
    file.ignore();
    getline(file,m_description);
}



