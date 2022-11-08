//
// Created by More on 31/10/2022.
//

#include "Client.h"

Client::Client(string n, string a, string p) {
    name = n;
    address = a;
    phone = p;
}

void Client::display() {
    cout << "---------- " << name << " ----------" << endl;
    cout << "Address: " << address << endl;
}

string Client::get_name() {
    return name;
}

string Client::get_address() {
    return address;
}

string Client::get_phone() {
    return phone;
}
