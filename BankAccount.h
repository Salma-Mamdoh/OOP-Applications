//
// Created by More on 31/10/2022.
//
#include "Client.h"
#ifndef ASS_2_BANKACCOUNT_H
#define ASS_2_BANKACCOUNT_H


class BankAccount {
protected:
    string accountID;
    int Balance;
public:
    BankAccount();
    BankAccount(string ac , int b);
    virtual void withdraw(int x);
    virtual void deposit(int x);
    string get_id();
    int get_balance();
    void display();

};


#endif //ASS_2_BANKACCOUNT_H
