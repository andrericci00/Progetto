//
// Created by 182913 on 06/03/2023.
//

#include "Transaction_out.h"
Transaction_out::Transaction_out() : Transaction(){}
Transaction_out::Transaction_out(float amount, const string &description) : Transaction(){}
string Transaction_out::getType() const {
    return "Uscita";
}
void Transaction_out::save(ofstream &file) const {
  file << getType() << endl;
  file << m_money << endl;
  file << m_description << endl;
}

void Transaction_out::load(ifstream &file) {
  file >> m_money;
  file.ignore();
  getline(file,m_description);
}