/*
From:ITC
11
STL defects
11.6
"STL out of bounds
"
11.6.4
deque assignment out of bounds 
*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;                                                                                                       
void STL_outof_bounds_004() {
	deque<int>temp;
	temp.push_back(1);
	temp.push_back(2); // /*Tool should detect this line as error*/ /*ERROR:STL error*/
	int a = temp[2];
	cout << a;
}
