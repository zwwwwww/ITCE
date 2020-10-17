/*
From:ITC
11
STL defects
11.13
"Mismatching containers
"
11.13.1
Sort the elements in an empty list container
*/
#include<iostream>	
using namespace std;	
#include<vector>
#include<List>
void func_001(vector<int>v) {
	v.push_back(1);
	v.push_back(2);
}
void mismaching_001() {
	vector<int>v;
	func_001(v);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}
