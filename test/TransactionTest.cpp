
#include "gtest/gtest.h"
#include "../Transaction.h"

TEST(Transaction, TransactionConstructor) {
    Transaction* t=new Transaction(100,Entrata,"prova");
    t->Modify(0,"prova2");
    ASSERT_EQ("prova2",t->description);
}

