#include "Stringset.h"
// empty constructor 
Stringset::Stringset()
{
}
// constructor takes the string 
Stringset::Stringset(string str)
{
	string ss;
	str.erase(remove(str.begin(), str.end(), ','), str.end());
	str.erase(remove(str.begin(), str.end(), '.'), str.end());
	int counter = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			counter++;
		}
		else {
			if (counter > 1) {
				str.erase(remove(str.begin() + i - counter + 1, str.begin() + i, ' '), str.begin() + i);
			}
			counter = 0;
		}
	}
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ' ) {
			ss += str[i];
		}
		else {
		    add_string(ss);
			ss.clear();
		}
		
	}
	
}
// constructor takes the name of file 
Stringset::Stringset(string str, string str2)
{
	string s = str +"."+ str2;
	fstream file;
	file.open(s, ios::in);
	while (file >> s) {
		for (int i = 0; i < s.length(); i++) {
			s[i] = tolower(s[i]);
		}
		s.erase(remove(s.begin(), s.end(), '.'), s.end());
		s.erase(remove(s.begin(), s.end(), ','), s.end());
		add_string(s);
	}
}
// add string 
vector<string>& Stringset::add_string(string str)
{
	vec.push_back(str);
	return vec;
}
// remove string 
vector<string>& Stringset::remove_string(string str)
{
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == str) {
			vec.erase(vec.begin() + i);
		}
	}
	return vec;
}
// clear all strings 
vector<string>& Stringset::clear_set()
{
	vec.clear();
	return vec;
}
// retune the number of strings 
int  Stringset::num_strings()
{
	return vec.size();
}
// print all strings
void Stringset::print_strings()
{
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "  ";
	}
	cout << endl;
}
// overloading + operator 
Stringset Stringset::operator+(Stringset x)
{
	Stringset Result;
	Result.vec.insert(Result.vec.end(), this->vec.begin(), this->vec.end());
	Result.vec.insert(Result.vec.end(), x.vec.begin(), x.vec.end());

	return Result;
}
// overloading * operation to get intersection between 2 strings 
Stringset Stringset::operator*(Stringset x)
{
	Stringset Result;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < x.vec.size(); j++) {
			if (vec[i] == x.vec[j]) {
				Result.add_string(vec[i]);
				//cout << vec[i] << " identiacal  " << x.vec[j] << endl;
			}
			else {
				//cout << vec[i] << "   " << x.vec[j] << endl;
			}
		}
	}
	return Result;
}
// similarity function 
Stringset Stringset::Similarity(Stringset x)
{
	Stringset Result;
	Result= this->operator*(x);
	int similarity_rate =round( (Result.vec.size()) / (sqrt(this->vec.size()) * sqrt(x.vec.size())));
	if (similarity_rate == 0) {
		cout << "Not similar" << endl;
	}
	else {
		cout << "Similar" << endl;
	}
	return Result;
}


