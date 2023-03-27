//
// Created by 182913 on 06/03/2023.
//

#ifndef LABORATORIO_TRANSACTION_H
#define LABORATORIO_TRANSACTION_H
#include <fstream>
#include <string>
using namespace std;

class Transaction {
public:
    Transaction();
    Transaction(float amount, const string& description);

    float getAmount() const;
    string getDescription() const;
    virtual string getType() const=0;
    void print() const;
    virtual void save(ofstream& file) const=0;
    virtual void load(ifstream& file)=0;

    float m_money;
    string m_description;

};


#endif //LABORATORIO_TRANSACTION_H
