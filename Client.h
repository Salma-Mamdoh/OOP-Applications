//
// Created by More on 31/10/2022.
//
#include <bits/stdc++.h>

using namespace std;
#ifndef ASS_2_CLIENT_H
#define ASS_2_CLIENT_H


class Client {
private:
    string name , address , phone;
public:
    Client();
    Client(string n , string a , string p);
    void display();
};


#endif //ASS_2_CLIENT_H
