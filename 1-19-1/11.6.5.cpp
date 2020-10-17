/*
From:ITC
11
STL defects
11.6
"STL out of bounds
"
11.6.5
the deleted deque is empty
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;                                                                                                           
void STL_outof_bounds_005() {
	deque<int>temp;
	temp.pop_back(); // /*Tool should detect this line as error*/ /*ERROR:STL error*/
}
