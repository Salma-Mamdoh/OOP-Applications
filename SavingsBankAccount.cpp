#include "SavingsBankAccount.h"
SavingsBankAccount::SavingsBankAccount() {}
// constructor of SavingsBankAccount 
SavingsBankAccount::SavingsBankAccount(string ac, int b, int x) {
    accountID = ac;
    Balance = b;
    minimumBalance = x;
}
// function to determine if i can withdraw or not depend on the amount of money in the account 
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
// function to determine if i can deposite or not depend on the amount of money in the account 
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
// function to display the account and new balance after withdraw or deposite
void SavingsBankAccount::display() {
    cout << "Account ID: " << accountID << endl << "Balance: " << Balance << endl;
    cout << "And this Account is Saving" << endl;
}


