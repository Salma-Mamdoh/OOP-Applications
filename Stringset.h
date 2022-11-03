#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;

class Stringset
{
private:
	vector<string>vec;
	string str2;
public:
	Stringset();
	Stringset(string str); // take string 
    Stringset(string str,string str2);//file name with 
	vector<string>& add_string(string str);
	vector<string>& remove_string(string str);
	vector<string>& clear_set();
	int  num_strings();
	void print_strings();
	Stringset operator+(Stringset x);
	Stringset operator*(Stringset x);
	Stringset Similarity(Stringset x);
};

