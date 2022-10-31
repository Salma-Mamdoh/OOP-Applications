//
// Created by More on 31/10/2022.
//

#include "Client.h"

Client::Client(string n, string a, string p) {
    n = name;
    a = address;
    p = phone;
}

void Client::display() {
    cout << "---------- " << name << " ----------" << endl;
    cout << "Address: " << address << endl;
}
