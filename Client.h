// client class
#pragma once
#include<iostream>
#include<string>
#include<map>
#include <bits/stdc++.h>
using namespace std;
#ifndef ASS_2_CLIENT_H
#define ASS_2_CLIENT_H
class Client {
private:
    string name, address, phone;
public:
    Client();
    Client(string n, string a, string p);
    string get_name();
    string get_address();
    string get_phone();
    void display();
};
#endif