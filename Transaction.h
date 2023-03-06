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
    Transaction(float importo, const string& description);

    float getImporto() const;
    string getDescription() const;
    virtual string getType() const = 0;


};


#endif //LABORATORIO_TRANSACTION_H
