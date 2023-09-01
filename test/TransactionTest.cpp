
#include "gtest/gtest.h"
#include "../Transaction.h"

TEST(Transaction, TransactionConstructor) {
    Transaction* t=new Transaction(100,Entrata,"prova");
    t->Modify(0,"prova2");
    ASSERT_EQ("prova2",t->getDescription());

}
TEST(TransactionTest, NegativeAmount) {
    // Verifica che il costruttore generi un'eccezione quando l'importo è negativo
    EXPECT_THROW({
                     try {
                         Transaction transaction(-100.0, Entrata, "negative amount");
                     }
                     catch (const std::invalid_argument& e) {

                         EXPECT_STREQ(e.what(), "L'importo deve essere positivo.");
                         throw;
                     }
                 }, std::invalid_argument);
}



