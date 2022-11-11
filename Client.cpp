#include "Client.h"
// constructor 
Client::Client(string n, string a, string p) {
    name = n;
    address = a;
    phone = p;
}
// function to display client information 
void Client::display() {
    cout << "---------- " << name << " ----------" << endl;
    cout << "Address: " << address << endl;
}
// getter to get client name 
string Client::get_name() {
    return name;
}
// getter to get client address
string Client::get_address() {
    return address;
}
// getter to get client phone 
string Client::get_phone() {
    return phone;
}