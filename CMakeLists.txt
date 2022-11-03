cmake_minimum_required(VERSION 3.22)
project(ass_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(ass_2 main.cpp Client.cpp Client.h BankAccount.cpp BankAccount.h SavingsBankAccount.cpp SavingsBankAccount.h BankApplication.cpp BankApplication.h)
