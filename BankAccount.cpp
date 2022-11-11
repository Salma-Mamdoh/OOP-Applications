#include "BankAccount.h"
BankAccount::BankAccount() {}
// constructor 
BankAccount::BankAccount(string ac, int b) {
    accountID = ac;
    Balance = b;
}
// function to determine if i can withdraw or not depend on the amount of money in the account 
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
// function to determine if i can deposite or not depend on the amount of money in the account 
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
// function to display the account and new balance after withdraw or deposite
void BankAccount::display() {
    cout << "Account ID: " << accountID << endl << "Balance: " << Balance << endl;
    cout << "And this Account is basic" << endl;
}
// getter to get id 
string BankAccount::get_id() {
    return accountID;
}
//getter to get balance 
int BankAccount::get_balance() {
    return Balance;
}

