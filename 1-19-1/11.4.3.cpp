/*
From:ITC
11
STL defects
11.4
"STLsctr
"
11.4.3
substr(£©function error
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;                                                                                                     
void STL_sctr_003() {
	string s = "hello";
	char c = s.substr(0, 3);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
