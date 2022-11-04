// App Assignment 2.cpp : 
// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 2
// Program Name: BigReal
// Author1 and ID and Group: Roaa Talat Mohamed  ID: 20210138 (a, b, c, d, e, f, g)
// Author2 and ID and Group: Salma Mamdoh Salma  ID:20210162 (h , i)
// Author3 and ID and Group:

#include "BigReal.h"
#include "BigDecimalInt2.h"
int main() {
    string  n1 = "-11.9000000000000000000000000000000001", n3 = "1.", n4 = "7";
    BigDecimalInt2 n5("-888");
    BigReal n; //Default constructor
    BigReal input1(n1), input3(n5);
    BigReal input2 = n; // Copy constructor
    BigReal input4 = move(input1);// Move constructor
    BigReal input5 = move(input1);// Move assignment
    BigReal input6(n); //copy assignment
    cout << "-----------tests for + operator ------------" << endl;
    BigReal r1("15.66");
    BigReal r2("7000.963");
    r1 + r2;
    cout << endl;
    BigReal r3("-15.66");
    BigReal r4("-7000.963");
    r3 + r4;
    cout << endl;
    BigReal r5("+15.66");
    BigReal r6("-7000.963");
    r5 + r6;
    cout << endl;
    BigReal r7("-15.66");
    BigReal r8("+7000.963");
    r7 + r8;
    cout << endl;
    cout << "-----------tests for - operator ------------" << endl;
    BigReal r9("+90000.0002");
    BigReal r10("264.60544");
    r9 - r10;
    cout << endl;
    BigReal r11("-90000.0002");
    BigReal r12("-264.60544");
    r11 - r12;
    cout << endl;
    BigReal r13("+90000.0002");
    BigReal r14("-264.60544");
    r13 - r14;
    cout << endl;
    BigReal r15("-90000.0002");
    BigReal r16("+264.60544");
    r15 - r16;
    cout << endl;



}