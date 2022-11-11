// bankaccount class 
#include "Client.h"
#ifndef ASS_2_BANKACCOUNT_H
#define ASS_2_BANKACCOUNT_H
class BankAccount {
protected:
    string accountID;
    int Balance;
public:
    BankAccount();
    BankAccount(string ac, int b);
    virtual bool withdraw(int x);
    virtual bool deposit(int x);
    string get_id();
    int get_balance();
    virtual void display();

};
#endif 