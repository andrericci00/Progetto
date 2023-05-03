cmake_minimum_required(VERSION 3.24)
project(Laboratorio)


set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES Transaction.cpp Transaction.h BankAccount.cpp BankAccount.h)
add_executable(Laboratorio main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Laboratorio core)


