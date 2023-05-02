add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, .lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp BankAccountTest.cpp TransactionTest.cpp)
add_executable(runBankAccountTests runTransactionTests ${TEST_SOURCE_FILES})
target_link_libraries(runBankAccountTests runTransactionTests gtest gtest_main core)