//
// Created by More on 03/11/2022.
//

#ifndef ASS_2_BANKAPPLICATION_H
#define ASS_2_BANKAPPLICATION_H
#include "Client.h"
#include "BankAccount.h"
#include "SavingsBankAccount.h"

class BankApplication {
private:
    map <string, Client> map_client;
    map <string, BankAccount> map_account;
    map <string, SavingsBankAccount> map_saving;
public:
    BankApplication();
    void addClient();
    void addBankAccount(int i);

};


#endif //ASS_2_BANKAPPLICATION_H
