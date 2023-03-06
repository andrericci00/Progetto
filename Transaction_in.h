//
// Created by 182913 on 06/03/2023.
//

#ifndef LABORATORIO_TRANSACTION_IN_H
#define LABORATORIO_TRANSACTION_IN_H
#include "Transaction.h"

class Transaction_in : public Transaction{
public:
    Transaction_in();
    Transaction_in(float importo, const string& description);

    virtual string getType() const override;
    virtual void save(ofstream& file) const override;
    virtual void load(ifstream& file) override;

};


#endif //LABORATORIO_TRANSACTION_IN_H
