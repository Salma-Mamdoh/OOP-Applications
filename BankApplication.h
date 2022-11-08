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
    map <string, pair<string , pair<string , string>>> map_client {{"FCAI-001",{"ammar",{"shoubra","01111111111"}}},{"FCAI-002",{"ali",{"zayed","01222222222"}}}};
    map <string, int> map_account{{"FCAI-001",1200}};
    map <string, int> map_saving{{"FCAI-002", 1500}};
public:
    BankApplication();
    void addClient();
    void addBankAccount(int i);
    void List_Clients_and_Accounts(string str);
    void Withdraw_Money(string str , int n);
    void Deposit_Money(string str , int n);
};


#endif //ASS_2_BANKAPPLICATION_H
