/*
From:ITC
11
STL defects
11.2
useless calls
11.2.11
" After emptying the vector container, delete the tail element"
*/
#include<iostream>	
using namespace std;	
#include<vector>void useless_call_011() {
	vector<int>v = { 1,2,3 };
	v.pop_back();/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}