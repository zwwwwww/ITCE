/*
From:ITC
11
STL defects
11.7
"STL missing comparison
"
11.7.5
The size of the copied vector is not compared
*/
#include<iostream>	
using namespace std;	
#include<vector>	
void missing_005() {
	vector<int>v1(2);
	vector<int>v2(10);
	for (int i = 0; i < 10; i++) {
		v2[i] = i;
	}
	if (v1.size() < v2.size()) {
		return;
	}
	else
	v1.assign(v2.begin(), v2.end());/*Tool should detect this line as error*/ /*ERROR:STL error*/
}