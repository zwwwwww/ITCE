/*
From:ITC
11
STL defects
11.2
useless calls
11.2.5
clear() a empty vector container
*/
#include<iostream>	
using namespace std;	
#include<vector>void useless_call_005() {
	vector<int>v;
	v.push_back(1);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/	
}