/*
From:ITC
10
Simple type defects
10.5
string
10.5.2
String literal Hello World doesnt match length argument for substr()
*/
#include<iostream>
#include<string.h>
using namespace std;                                                                                                                           
void string_002() {
	string s = ""hello world"";
	string s1 = s.substr(2);/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
	cout << s1;
}