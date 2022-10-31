//
// Created by More on 31/10/2022.
//
#include "Client.h"
#ifndef ASS_2_BANKACCOUNT_H
#define ASS_2_BANKACCOUNT_H


class BankAccount {
private:
    string accountID;
    int Balance;
public:
    BankAccount();
    BankAccount(string ac , int b);
    void withdraw(int x);
    void deposit(int x);
    void display();

};


#endif //ASS_2_BANKACCOUNT_H
