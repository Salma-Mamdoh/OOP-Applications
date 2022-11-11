// class of savingbankaccount 
#include "Client.h"
#include "BankAccount.h"
#ifndef ASS_2_SAVINGSBANKACCOUNT_H
#define ASS_2_SAVINGSBANKACCOUNT_H
class SavingsBankAccount : public BankAccount {
private:
    int minimumBalance;
public:
    SavingsBankAccount();
    SavingsBankAccount(string ac, int b, int x);
    bool withdraw(int x);
    bool deposit(int x);
    void display();
};
#endif 

