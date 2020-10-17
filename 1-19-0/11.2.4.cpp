/*
From:ITC
11
STL defects
11.2
useless calls
11.2.4
Delete iterator point to begin() of empty container
*/
#include<iostream>	
using namespace std;	
#include<vector>void useless_call_004() {
	vector<int>v;
	vector<int>::iterator it = v.begin();
	v.push_back(1);                         /*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}
