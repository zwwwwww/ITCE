/*
From:ITC
10
Simple type defects
10.5
string
10.5.4
Comparison of identical string variables
*/
#include<iostream>
#include<string.h>
using namespace std;                                                                                                                        
void string_004() {
	const char *s1 = ""hello"";
	int a = strcmp(s1, s1);/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
		cout << s1;

}