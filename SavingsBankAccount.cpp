//
// Created by More on 31/10/2022.
//

#include "SavingsBankAccount.h"

SavingsBankAccount::SavingsBankAccount() {}

SavingsBankAccount::SavingsBankAccount(string ac, int b, int x) {
    accountID = ac ;
    Balance = b;
    minimumBalance = x;
}

bool SavingsBankAccount::withdraw(int x) {
    if (x > Balance - minimumBalance)
        cout << "Sorry. This is more than what you can withdraw.\n";
    else
    {
        Balance = Balance - x;
        cout << "Done\n";
        return true;
    }
    return false;
}

bool SavingsBankAccount::deposit(int x) {
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

void SavingsBankAccount::display() {
    cout << "Account ID: " << accountID << endl << "Balance: " << Balance << endl;
    cout << "And this Account is Saving" << endl;
}

