/*
From:ITC
11
STL defects
11.6
"STL out of bounds
"
11.6.3
The delete vector is empty
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;                                                                                                       
void STL_outof_bounds_003() {
	vector<int>vec;
	vec.push_back(1);
	vec.pop_back(); // /*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}