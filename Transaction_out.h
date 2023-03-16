//
// Created by 182913 on 06/03/2023.
//

#ifndef LABORATORIO_TRANSACTION_OUT_H
#define LABORATORIO_TRANSACTION_OUT_H


#include "Transaction.h"

class Transaction_out : public Transaction {
public:
    Transaction_out();
    Transaction_out(float amount, const string& description);

    virtual string getType() const override;

    virtual void save(ofstream& file) const override;
    virtual void load(ifstream& file) override;

    float m_money;
};

#endif //LABORATORIO_TRANSACTION_OUT_H
