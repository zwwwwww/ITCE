/*
From:ITC
11
STL defects
11.4
"STLsctr
"
11.4.4
erase(£©function error
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;                                                                                                                     
void STL_sctr_004() {
	string s = "helloworld";
	string S = s.erase(4);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	cout << S;
}