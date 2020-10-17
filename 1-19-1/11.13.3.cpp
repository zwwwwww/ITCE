/*
From:ITC
11
STL defects
11.13
"Mismatching containers
"
11.13.3
Sort the elements in an empty list container
*/
#include<iostream>	
using namespace std;	
#include<deque>
#include<vector>
void func_003(deque<int>d) {
	d.clear();
}
void mismaching_003() {
	vector<int>v = { 1,2,3 };
	func_003(v);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
