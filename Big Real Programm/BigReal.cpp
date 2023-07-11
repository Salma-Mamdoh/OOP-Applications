#include "BigReal.h"
#include"BigDecimalInt2.h"
#include<regex>
#include<cmath>
bool BigReal::checkValidInput(string input)
{
    regex validInput("[+-]?\\d*\\.\\d*");
    return regex_match(input, validInput);
}

// constructor that takes a string as an input.
void BigReal::setNumber(string num)
{
    bool validNumber = checkValidInput(num);
    if (validNumber)
    {
        int i = 0;
        while (num[i] != '.') {
            number1.push_back(num[i]);
            i++;
        }
        if ((num[0] != '+' && num[0] != '-' && num[0] == '.') || (num[0] == '+' || num[0] == '-') && num[1] == '.')number1 = '0';
        if (i + 1 == num.length())number2 = "0";
        else number2 = num.erase(0, i + 1);
        if (number1[0] == '+')
        {
            number1.erase(0, 1);
            sign = '+';
        }
        else if (number1[0] == '-')
        {
            number1.erase(0, 1);
            sign = '-';
        }
        else
        {
            sign = '+';
        }
    }
    else
    {
        cout << "Invalid" << "\n";
        exit(1);
    }
}
BigReal::BigReal(BigDecimalInt2 bigInteger) {
    bigInteger.number.push_back('.');
    setNumber(bigInteger.number);
    sign = bigInteger.signint;
}

BigReal::BigReal(double realNumber)
{
    string s = to_string(realNumber);
    setNumber(s);
}

BigReal::BigReal(string num) {
    setNumber(num);
}

BigReal::BigReal(const BigReal& other) {
    number1 = other.number1;
    number2 = other.number2;
    sign = other.sign;
}

BigReal& BigReal::operator=(BigReal& other)
{
    if (this != &other) {
        number1 = other.number1;
        number2 = other.number2;
        sign = other.sign;
    }
    return *this;
}

BigReal::BigReal(BigReal&& other)
{
    number1 = other.number1;
    number2 = other.number2;
    sign = other.sign;
    number1 = "0";
    number2 = "0";
    sign = '+';
}

BigReal& BigReal::operator=(BigReal&& other)
{
    if (this != &other) {
        number1 = other.number1;
        number2 = other.number2;
        sign = other.sign;
        number1 = "0";
        number2 = "0";
        sign = '+';
    }
    return *this;
}

string BigReal::add_zeros_toFraction(string s1, string s2)
{
    if (s1.length() != s2.length()) {
        string addzerostofraction;
        int diff = s1.length() - s2.length();
        for (int i = 0; i < abs(diff); i++) {
            addzerostofraction += '0';
        }
        string newmintfraction;
        if (s1.length() < s2.length()) {
            newmintfraction = s1 + addzerostofraction;
            s1 = newmintfraction;
            return s1;
        }
        else {
            newmintfraction = s2+ addzerostofraction;
            s2 = newmintfraction;
            return s2;
        }
    }

}

int BigReal::getmax(string str1, string str2 ,string str3 , string str4)
{
    // 1---> if str1 is max  // 2----> if str2 is max
    // this function work in decimal part and fraction part
    // str1 , str2 for decimal part , str3 , str4 for fraction part
    if (str1.length() > str2.length()) {
        return 1;
    }
    else if (str2.length() > str1.length()) {
        return 2;
    }
    else if ((str1 == str2) && (str3 == str4)) {
        return 1;
    }
    else if ((str1 == str2) && (str3 != str4)) {
        for (int i = 0; i < min(str3.length(), str4.length()); i++) {
            if (str3[i] - '0' > str4[i] - '0') {
                return 1;
                break;
            }
            else if (str4[i]-'0' > str3[i]-'0') {
                return 2;
                break;
            }
            else {
                continue;
            }
        }
        return 0;
    }
    else if (str1.length() == str2.length())
    {
        for (int i = 0; i < str1.length(); i++) {

            if (str1[i] - '0' == str2[i] - '0') {
                continue;
            }
            else if (str1[i] - '0' < str2[i] - '0') {
                return 2;
                break;
            }
            else if (str1[i] - '0' > str2[i] - '0') {
                return 1;
                break;
            }
        }
        return 0;
    }
}

string BigReal::addition(string str1, string str2, string str3, string str4)
{
    // to add fraction parts
    string big, small; // length of fractions
    if (min(str3.length(), str4.length()) == str3.length()) {
        str3= add_zeros_toFraction(str3, str4);
    }
    else {
        str4 = add_zeros_toFraction(str3, str4);
    }
    if (getmax("00", "00", str3, str4) == 1) {
        big = str3;
        small = str4;
    }
    else {
        big = str4;
        small = str3;
    }
    string FinalRFraction, reResultFraction, sepF1, sepF2, sepF3;
    int xF, yF, zF, carryF = 0;
    for (int i = big.size() - 1; i >= 0; i--) {
        sepF1 += big[i];
        xF = stoi(sepF1);
        xF += carryF;
        sepF2 += small[i];
        yF = stoi(sepF2);
        zF = xF + yF;
        if (xF + yF < 10) {
            carryF = 0;
            sepF3 = to_string(zF);
            reResultFraction += sepF3;
        }
        else {
            carryF = 1;
            zF -= 10;
            sepF3 = to_string(zF);
            reResultFraction += sepF3;
        }
        sepF1.clear();
        sepF2.clear();
        sepF3.clear();
    }
    int carrytodecimal = 0;
    if (carryF == 1) {
        carrytodecimal++;
    }
    int jF;
    for (int i = 0; i <= reResultFraction.length(); i++) {
        if (reResultFraction[i] == '0') {
            continue;
        }
        else {
            jF = i;
            break;
        }
    }
    for (int i = reResultFraction.length() - 1; i >= jF; i--) {
        FinalRFraction += reResultFraction[i];
    }

    // to add decimal parts
    string max, min;
    if (str1.length() > str2.length()) {
        max = str1;
        min = str2;
    }
    else {
        min = str1;
        max = str2;
    }
    // if 2 inputs are not in the same length we will add zeros at the begining of the smaller number of them
    string addzeros,stt1,stt2;
    int diff2 = max.size() - min.size();
    for (int i = 0; i < diff2; i++) {
        addzeros += '0';
    }
    string newmin = addzeros + min;
    min = newmin;
    stt1 = max, stt2 = min;
    string FinalResult, reResult, sep1, sep2, sep3;
    int x, y, z, carry = 0;
    for (int i = stt1.size() - 1; i >= 0; i--) {
        sep1 += stt1[i];
        x = stoi(sep1);
        x += (carry + carrytodecimal);
        sep2 += stt2[i];
        y = stoi(sep2);
        z = x + y;
        if (x + y < 10) {
            carry = 0;
            sep3 = to_string(z);
            reResult += sep3;
            carrytodecimal = 0;
        }
        else {
            carry = 1;
            z -= 10;
            sep3 = to_string(z);
            reResult += sep3;
            carrytodecimal = 0;
        }
        sep1.clear();
        sep2.clear();
        sep3.clear();
    }
    if (carry == 1) {
        reResult += "1";
    }
    // to delete zeros in the left side
    //cout << reResult << endl;
    int j= reResult.size() - 1;
    for (int i = reResult.size() - 1; i >= 0; i--) {
        if (reResult[i] == '0') {
            continue;
        }
        else {
            j = i;
            break;
        }
    }
    for (int i = j; i >= 0; i--) {
        FinalResult += reResult[i];
    }
    // FinalResult
    string strfinal = FinalResult + "." + FinalRFraction;
    return strfinal;
}

string BigReal::substraction(string str1, string str2, string str3, string str4)
{
    // substraction of fraction parts
    string big, small; // length of fractions
    if (min(str3.length(), str4.length()) == str3.length()) {
        str3 = add_zeros_toFraction(str3, str4);
    }
    else {
        str4 = add_zeros_toFraction(str3, str4);
    }
    // now each string has the same length
    // big string will be for big number and if this fraction is smaller than the small number the int carrytodeciamal
    // will be equal to 1
    string maxf, minf;
    int carrytodecimal = 0;
    if (getmax(str1, str2, str3, str4) == 1) {
        maxf = str3;
        minf = str4;
        if (str3 == str4) {
            carrytodecimal = 0;
        }
        else if (getmax("00", "00", str3, str4) == 2) {
            carrytodecimal++;
        }
    }
    else {
        maxf = str4;
        minf = str3;
        if (str3 == str4) {
            carrytodecimal = 0;
        }
        else if (getmax("00", "00", str3, str4) == 1) {
            carrytodecimal++;
        }
    }

    string FinalResultFraction, reResultFraction, sepF1, sepF2, sepF3;
    int xF, yF, zF, carryF = 0;
    for (int i = maxf.length() - 1; i >= 0; i--) {
        sepF1 += maxf[i];
        xF = stoi(sepF1);
        xF-= carryF;
        sepF2 = minf[i];
        yF = stoi(sepF2);
        if (xF >= yF) {
            zF = xF - yF;
            carryF = 0;
            sepF3 = to_string(zF);
        }
        else {
            carryF = 1;
            zF = (xF + 10) - yF;
            sepF3 = to_string(zF);
        }
        reResultFraction += sepF3;
        sepF1.clear();
        sepF2.clear();
        sepF3.clear();
    }
    // to delete zeros in the left side
    int jF;
    for (int i = 0; i <= reResultFraction.length(); i++) {
        if (reResultFraction[i] == '0') {
            continue;
        }
        else {
            jF = i;
            break;
        }
    }
    for (int i = reResultFraction.length() - 1; i >= jF; i--) {
        FinalResultFraction += reResultFraction[i];
    }

    // substraction of decimal parts
    string max, min;
    if (getmax(str1, str2, str3, str4) == 1) {
        max = str1;
        min = str2;
    }
    else {
        max = str2;
        min = str1;
    }
// if 2 inputs are not in the same length we will add zeros at the begining of the smaller number of them
    string addzeros;
    int diff2 = max.size() - min.size();
    for (int i = 0; i < diff2; i++) {
        addzeros += '0';
    }
    string newmin = addzeros + min;
    min = newmin;
    string s1 = max, s2 = min;
    string FinalResult, reResult, sep1, sep2, sep3;
    int x, y, z, carry = 0;
    for (int i = s1.length() - 1; i >= 0; i--) {
        sep1 += s1[i];
        x = stoi(sep1);
        x -= (carry + carrytodecimal);
        sep2 = s2[i];
        y = stoi(sep2);
        if (x >= y) {
            z = x - y;
            carry = 0;
            sep3 = to_string(z);
            carrytodecimal = 0;
        }
        else {
            carry = 1;
            z = (x + 10) - y;
            sep3 = to_string(z);
            carrytodecimal = 0;
        }
        reResult += sep3;
        sep1.clear();
        sep2.clear();
        sep3.clear();
    }
// to delete zeros in the left side
    int j= reResult.size() - 1;
    for (int i = reResult.size() - 1; i >= 0; i--) {
        if (reResult[i] == '0') {
            continue;
        }
        else {
            j = i;
            break;
        }
    }
    for (int i = j; i >= 0; i--) {
        FinalResult += reResult[i];
    }
    string finalstr = FinalResult + "." + FinalResultFraction;
    return finalstr;
}

BigReal BigReal::operator+(BigReal& other)
{
    BigReal Result;
    if ((this->sign == '+') && (other.sign == '+')) {
        Result.sign = '+';
        Result.number = addition(this->number1, other.number1, this->number2, other.number2);
        cout << Result.sign << " " << Result.number << endl;
    }
    else if ((this->sign == '-') && (other.sign == '-')) {
        Result.sign = '-';
        Result.number = addition(this->number1, other.number1, this->number2, other.number2);
        cout << Result.sign << " " << Result.number << endl;
    }
    else if (((this->sign == '-') && (other.sign == '+')) || ((this->sign == '+') && (other.sign == '-'))) {
        if (getmax(this->number1, other.number1, this->number2, other.number2) == 1) {
            Result.sign = this->sign;
        }
        else {
            Result.sign = other.sign;
        }
        Result.number = substraction(this->number1, other.number1, this->number2, other.number2);
        cout << Result.sign << " " << Result.number << endl;

    }
    return Result;
}

BigReal BigReal::operator-(BigReal& other)
{
    BigReal Result;
    if ((this->sign == '+') && (other.sign == '+')) { // +5.5-+2.5  +5.5-2.5
        if (getmax(this->number1, other.number1, this->number2, other.number2) == 1) {
            Result.sign = '+';
        }
        else {
            Result.sign = '-';
        }
        Result.number = substraction(this->number1, other.number1, this->number2, other.number2);
        cout << Result.sign << " " << Result.number << endl;
    }
    else if( (this->sign == '-') && (other.sign == '-')){
        if (getmax(this->number1, other.number1, this->number2, other.number2) == 1) {
            Result.sign = '-';
        }
        else {
            Result.sign = '+';
        }
        Result.number = substraction(this->number1, other.number1, this->number2, other.number2);
        cout << Result.sign << " " << Result.number << endl;
    }
    else if ((this->sign == '-') && (other.sign == '+')) {
        Result.sign = '-';
        Result.number = addition(this->number1, other.number1, this->number2, other.number2);
        cout << Result.sign << " " << Result.number << endl;
    }
    else if ((this->sign = '+') && (other.sign == '-')) {
        Result.sign = '+';
        Result.number = addition(this->number1, other.number1, this->number2, other.number2);
        cout << Result.sign << " " << Result.number << endl;

    }
    return Result;
}

void BigReal::set_number2(string str) {
    number2 = str;
}

bool BigReal::operator>(BigReal anotherReal) {
    if (this->number2.length() < anotherReal.number2.length())
        this->set_number2(add_zeros_toFraction( this->number2,anotherReal.number2));
    else
        anotherReal.set_number2(add_zeros_toFraction( this->number2,anotherReal.number2));
    if((this->sign == '+' && anotherReal.sign == '-') ||
       (this->sign == '+' && getmax(this->number1, anotherReal.number1, this->number2, anotherReal.number2) == 1) ||
       (this->sign == '-' && anotherReal.sign == '-' && getmax(this->number1, anotherReal.number1, this->number2, anotherReal.number2) == 2))
        return true;
    return false;
}

bool BigReal::operator<(BigReal anotherReal) {
    if (this->number2.length() < anotherReal.number2.length())
        this->set_number2(add_zeros_toFraction( this->number2,anotherReal.number2));
    else
        anotherReal.set_number2(add_zeros_toFraction( this->number2,anotherReal.number2));
    if((this->sign == '-' && anotherReal.sign == '+') ||
       (this->sign == '-' && anotherReal.sign == '-' && getmax(this->number1, anotherReal.number1, this->number2, anotherReal.number2) == 1))
        return true;
    return false;
}

int BigReal::size() {
    return (this->number1.length() + this->number2.length());
}

int BigReal::get_sign() {
    if (this->sign == '+')
        return 1;
    else
        return -1;
}

ostream &operator<<(ostream &out, BigReal num) {
    out<< num.sign <<num.number1 <<'.'<<num.number2;
    return out;
}

istream &operator>>(istream &out, BigReal num) {
    out >> num.number;
    return out;
}


