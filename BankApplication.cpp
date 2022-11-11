#include "BankApplication.h"
// bankapplication constructor which display menu and take the choose from user 
BankApplication::BankApplication() {
    cout << "Welcome to FCAI Banking Application\n1. Create a New Account\n2. List Clients and Accounts\n";
    cout << "3. Withdraw Money\n4. Deposit Money\n";
    int choose; cin >> choose;
    if (choose > 5 || choose < 1)
        BankApplication();
    else if (choose == 1) {
        int i;
        addClient();
        cout << "What Type of Account Do You Like? (1) Basic (2) Saving : \n";
        cin.ignore();
        cin >> i;
        if (i == 1)
            addBankAccount(1);
        else if (i == 2)
            addBankAccount(2);
    }
    else if (choose == 2)
    {
        string id;
        cout << "Enter the id of your account: ";
        cin >> id;
        List_Clients_and_Accounts(id);
    }
    else if (choose == 3)
    {
        string id; int n;
        cout << "Enter the id of your account: ";
        cin >> id;
        cout << "Please Enter The Amount to Withdraw: ";
        cin >> n;
        Withdraw_Money(id, n);
    }
    else if (choose == 4)
    {
        string id; int n;
        cout << "Enter the id of your account: ";
        cin >> id;
        cout << "Please Enter The Amount to Deposirt: ";
        cin >> n;
        Deposit_Money(id, n);
    }
    cout << "Thank you";
}
// function to add client 
void BankApplication::addClient() {
    string name, address, phone, accountID;;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter your phone number: ";
    cin >> phone;
    accountID = "FCAI-" + to_string(map_client.size() + 1);
    map_client[accountID] = { name,{address,phone} };
}
// function to add bankaccount 
void BankApplication::addBankAccount(int i)
{
    string accountID;
    int Balance;
    cout << "Please Enter the Starting Balance: ";
    cin.ignore();
    cin >> Balance;
    accountID = "FCAI-" + to_string(map_client.size() + 1);
    if (i == 1)
        map_account[accountID] = Balance;
    else
        map_saving[accountID] = Balance;
    cout << "An account was created with ID  " << accountID << "  and Starting Balance  " << Balance << endl;
}
// function to list the information of the client and display its information 
void BankApplication::List_Clients_and_Accounts(string str) {
    if (map_client.count(str))
    {
        Client c(map_client[str].first, map_client[str].second.first, map_client[str].second.second);
        c.display();
        if (map_account.count(str))
        {
            BankAccount ba(str, map_account[str]);
            ba.display();
        }
        else
        {
            SavingsBankAccount sba(str, map_account[str], 1000);
            sba.display();
        }
    }
    else
        cout << "Sorry this account does not exist" << endl;
}
// function to withdraw money 
void BankApplication::Withdraw_Money(string str, int n) {
    if (map_client.count(str))
    {
        if (map_account.count(str))
        {
            BankAccount ba(str, map_account[str]);
            if (ba.withdraw(n))
            {
                map_account[str] = map_account[str] - n;
                cout << "Account ID :" << str << endl;
                cout << "New Balance: " << map_account[str] - n << endl;
            }
        }
        else
        {
            SavingsBankAccount sba(str, map_account[str], 1000);
            if (sba.withdraw(n))
            {
                map_saving[str] = map_saving[str] - n;
            }
        }
    }
    else
        cout << "Sorry this account does not exist" << endl;
}
// function to deposit money 
void BankApplication::Deposit_Money(string str, int n) {
    if (map_client.count(str))
    {
        if (map_account.count(str))
        {
            BankAccount ba(str, map_account[str]);
            if (ba.deposit(n))
            {
                map_account[str] = map_account[str] + n;
                cout << "Account ID :" << str << endl;
                cout << "New Balance: " << map_account[str] + n << endl;
            }
        }
        else
        {
            SavingsBankAccount sba(str, map_account[str], 1000);
            if (sba.deposit(n))
            {
                map_saving[str] = map_saving[str] + n;
            }
        }
    }
    else
        cout << "Sorry this account does not exist" << endl;
}
