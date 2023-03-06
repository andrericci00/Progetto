//
// Created by 182913 on 06/03/2023.
//

#ifndef LABORATORIO_TRANSACTION_OUT_H
#define LABORATORIO_TRANSACTION_OUT_H


#include "Transaction.h"

class Transaction_out : public Transaction {
public:
    Transaction_out();
    Transaction_out(float importo, const string& description);

    virtual string getType() const;

    virtual void save(ofstream& file) const ;
    virtual void load(ifstream& file);
};

#endif //LABORATORIO_TRANSACTION_OUT_H
