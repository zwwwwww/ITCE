/*
From:ITC
11
STL defects
11.2
useless calls
11.2.14
The calling function inserts a negative number into a container of type char
*/
#include<iostream>	
using namespace std;	
#include<vector>void useless_call_014() {
	vector<char>v = { 'a','b' };
	v.push_back('c');/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}