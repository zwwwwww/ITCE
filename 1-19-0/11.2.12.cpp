/*
From:ITC
11
STL defects
11.2
useless calls
11.2.12
"After emptying the vector container, delete the tail element"
*/
#include<iostream>	
using namespace std;	
#include<List>
void useless_call_012() {
	list<int>l;
	l.push_back(1);
	l.push_back(3);
	l.pop_back();/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}