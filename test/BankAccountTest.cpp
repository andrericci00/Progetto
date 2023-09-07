//
// Created by 182913 on 02/05/2023.
//
#include "gtest/gtest.h"
#include "../BankAccount.h"

TEST(BankAccount, BankAccountbalance) {
     BankAccount b;
     ASSERT_EQ(b.GetBalance(),0);
}

TEST(MakeTransactionTest, balanceMakeTransaction) {
    BankAccount b;
    b.MakeTransaction(50,transactionType::Entrata,"Entrata");
    b.MakeTransaction(30,transactionType::Uscita,"Uscita");
    b.Deposit(40,"Deposito");
    ASSERT_EQ(b.GetBalance(),60);

}

TEST(BankAccountTest, WithdrawMoreThanBalance) {
    BankAccount account;
    account.SetBalance(100.0);

    // Tentativo di prelevare un importo maggiore del saldo
    ASSERT_THROW({
                     account.Withdrawing(200.0, "Prelievo");
                 },
                 std::runtime_error);

    // Verifica che il saldo sia rimasto invariato
    EXPECT_DOUBLE_EQ(account.GetBalance(), 100.0);
}




