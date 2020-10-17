/*
From:ITC
11
STL defects
11.2
useless calls
11.2.9
Insert int type value to call function in container of type char
*/
#include<iostream>	
using namespace std;	
#include<stack>;
void useless_call_009() {
	stack<int>s;
	s.push(1);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}