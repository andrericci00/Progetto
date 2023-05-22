//
// Created by 182913 on 02/05/2023.
//
#include "gtest/gtest.h"
#include "../BankAccount.h"

TEST(BankAccount, BankAccountbalance) {
     BankAccount b;
     b.balance=50;
    ASSERT_EQ(b.GetBalance(),50);
}