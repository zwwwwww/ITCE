/*
From:ITC
11
STL defects
11.4
"STLsctr
"
11.4.1
The return value type does not match the function type
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;                                                                                                                  
string fun() {
	string s = "abcd";
	return s;/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}

void STL_sctr_001() {
	string s = fun();
	cout << s;
}