/*
From:ITC
11
STL defects
11.2
useless calls
11.2.6
delete empty map key
*/
#include<iostream>	
using namespace std;	
#include<map>
void useless_call_006() {
	map<int, string>m;
	m[1] = ""one"";/*Tool should Not detect this line as error*/ /*ERROR:STL error*/	
}