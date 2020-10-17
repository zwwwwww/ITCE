/*
From:ITC
10
Simple type defects
10.5
string
10.5.3
Char literal compared with pointer foo
*/
#include<iostream>
#include<string.h>
using namespace std;                                                                                                                                     
 void strig_ 003() {
	char* foo;
	char c = 'a';
	foo = &c;/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
	cout << *foo;
}