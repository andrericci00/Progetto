//
// Created by 182913 on 06/03/2023.
//

#include "Transaction_out.h"
Transaction_out::Transaction_out() : Transaction(){}
Transaction_out::Transaction_out(float importo, const string &description) : Transaction(){}
string Transaction_out::getType() const {
    return "Uscita";
}
void Transaction_out::save(ofstream &file) const {

}

void Transaction_out::load(ifstream &file) {

}