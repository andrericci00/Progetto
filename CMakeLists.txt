cmake_minimum_required(VERSION 3.24)
project(Laboratorio)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laboratorio main.cpp Transaction.cpp Transaction.h Transaction_in.cpp Transaction_in.h Transaction_out.cpp Transaction_out.h)
