//
// Created by More on 03/11/2022.
//

#include "BankApplication.h"

BankApplication::BankApplication() {
    cout << "Welcome to FCAI Banking Application\n1. Create a New Account\n2. List Clients and Accounts\n";
    cout <<"3. Withdraw Money\n4. Deposit Money\n5.exit\n";
    int choose; cin >> choose;
    if (choose > 5 || choose < 1)
        BankApplication();
    else if(choose == 1) {

        int i;
        cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2: ";cin >> i;
        if (i == 1)
              addBankAccount(1) ;
        else if(i == 2)
            addBankAccount(2);


    }
//    else if(choose == 2)
//    {}
//    else if(choose == 3)
//    {}
//    else if(choose == 4)
//    {}
//    else if(choose == 5)
//    {
//    }

}

void BankApplication::addClient() {
    string name , address , phone;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Enter your address: ";
    cin.ignore();
    getline(cin , address);
    cout << "Enter your phone number: ";
    cin >> phone;
    Client c(name,address,phone);
    map_client["FCAI-" + to_string(map_account.size()+map_saving.size()+1)] = c;
}

void BankApplication::addBankAccount(int i)
{
    string accountID ;
    int Balance;
    cout << "Please Enter the Starting Balance: ";
    cin >> Balance;
    accountID = "FCAI-" + to_string(map_account.size()+map_saving.size()+1) ;
    BankAccount ba(accountID, Balance);
    SavingsBankAccount sa(accountID, Balance , 1000);
    if(i == 1)
        map_account[accountID] = ba;
    else
        map_saving[accountID] =  sa;
    cout << "An account was created with ID" <<  accountID << " and Starting Balance "<< Balance << endl;
}

