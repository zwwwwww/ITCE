/*
From:ITC
10
Simple type defects
10.5
string
10.5.1
String literal compared with variable foo
*/
#include<iostream>
#include<string.h>
using namespace std;                                                                                         
void string_001() {
	const char* s1 = ""helloworld"";
	const char* s2 = ""world"";
	int i = strcmp(s1, s2);/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
	cout << i;
}