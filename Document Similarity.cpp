// Document Similarity.cpp :
// author : salma Mamdoh sabry ---> ID->(20210162)
#include"Stringset.h"
using namespace std;
int main()
{
	cout << "--------string input------------" << endl;
	Stringset s1("Hallo in the program "); // constructor takes string 
	cout << s1.num_strings() << endl; // return number of words 
	s1.remove_string("the"); // remove "sabry" from string 
	cout << s1.num_strings() << endl;;
	s1.print_strings();// print all words in string 
	s1.clear_set(); // clear all the string 
	cout << s1.num_strings() << endl;
	s1.print_strings();
	cout << endl;
	cout << "----------------file input---------" << endl;
	Stringset s2("input", "txt"); // constructor takes file name 
	s2.num_strings();
	s2.print_strings();
	cout << "---------overloading + operator --------" << endl;
	Stringset s5("Hallo program here we are again ");
	Stringset s4 = s5 + s2;
	s4.print_strings();
	cout << endl;
	cout << "-------------overloading * operator ------" << endl;
	Stringset ss;
	Stringset s10("Hallo program Made by Salma Mamdoh ");
	ss=s10*s5;
	ss.print_strings();
	cout << "---------------Check Similarity------------" << endl;
	Stringset s3("salma Mamdoh");
	s3.Similarity(s2);
	cout << endl;
	s10.Similarity(s5);
}
