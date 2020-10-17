/*
From:ITC
11
STL defects
11.13
"Mismatching containers
"
11.13.4
Sort the elements in an empty list container
*/
#include<iostream>	
using namespace std;	
#include<map>
#include<vector>	
	
void func_004(map<int, string>m) {
	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
}
void mismaching_004() {
	map<int,string>v;
	func_004(v);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}
