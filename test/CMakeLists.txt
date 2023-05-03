cmake_minimum_required(VERSION 3.24)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, .lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp BankAccountTest.cpp TransactionTest.cpp)
add_executable(runBankAccountTests  ${TEST_SOURCE_FILES})
target_link_libraries(runBankAccountTests runTransactionTests gtest gtest_main core)