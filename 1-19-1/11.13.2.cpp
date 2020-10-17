/*
From:ITC
11
STL defects
11.13
"Mismatching containers
"
11.13.2
Sort the elements in an empty list container
*/
#include<iostream>	
using namespace std;	
#include<vector>
void func_002(vector<int>v) {
	v.push_back(0);
}
void mismaching_002() {
	vector<char> c;
	func_002(c);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}