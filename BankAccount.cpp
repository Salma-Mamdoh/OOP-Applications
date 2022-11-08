//
// Created by More on 31/10/2022.
//

#include "BankAccount.h"

BankAccount::BankAccount() {}

BankAccount::BankAccount(string ac, int b) {
    accountID = ac;
    Balance = b;
}

bool BankAccount::withdraw(int x) {
        if (x > Balance)
            cout << "Sorry. This is more than what you can withdraw.\n";
        else
        {
            Balance = Balance - x;
            cout << "Done\n";
            return true;
        }
        return false;
}

bool BankAccount::deposit(int x) {
    if (x < 100)
        cout << "Sorry. This is less than what you can deposit.\n";
    else
    {
        Balance = Balance + x;
        cout << "Done\n";
        return true;
    }
    return false;
}

void BankAccount::display() {
    cout << "Account ID: " << accountID << endl << "Balance: " << Balance << endl;
    cout << "And this Account is basic" << endl;
}

string BankAccount::get_id() {
    return accountID;
}

int BankAccount::get_balance() {
    return Balance;
}


