/*
From:ITC
11
STL defects
11.6
"STL out of bounds
"
11.6.2
loop assignment out of bounds
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;                                                                                                    
void STL_outof_bounds_002() {
	vector<int>vec(5);
	int i;
	for (i = 0; i < 10; i++) { // /*Tool should detect this line as error*/ /*ERROR:STL error*/
		vec.push_back(i);
	}
}