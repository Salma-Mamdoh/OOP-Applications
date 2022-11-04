#include<bits/stdc++.h>
#include"BigDecimalInt2.h"

using namespace std;
#ifndef BIGREAL
#define BIGREAL
class BigReal {
private:
    string number1, number2,number;
    char sign;
    void setNumber(string num);
    bool checkValidInput(string input);

public:
    BigReal(string realNumber);
    BigReal(BigDecimalInt2 bigInteger);
    BigReal(double realNumber = 0.0);
    BigReal(const BigReal& other);
    //BigReal& operator= (BigReal& other);
    BigReal& operator= (BigReal& other);
    //BigReal (BigReal&& other);
    BigReal(BigReal&& other);
    //BigReal& operator= (BigReal&& other);
    BigReal& operator= (BigReal&& other);
    string add_zeros_toFraction(string s1, string s2);
    static int  getmax(string str1, string str2,string str3 ,string str4);
    string addition(string str1, string str2, string str3, string str4);
    string substraction(string str1, string str2, string str3, string str4);
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);

};
#endif 
