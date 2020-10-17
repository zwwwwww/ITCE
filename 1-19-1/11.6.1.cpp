/*
From:ITC
11
STL defects
11.6
"STL out of bounds
"
11.6.1
assignment exceeds boundary
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;                                                                                                      
void STL_outof_bounds_001() {
	vector<int>vec;
	vec.push_back(1);
	vec.push_back(2); // /*Tool should detect this line as error*/ /*ERROR:STL error*/
	int a = vec[2];
	cout << a;
}
