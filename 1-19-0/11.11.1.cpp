/*
From:ITC
11
STL defects
11.11
"Redundant if remove
"
11.11.1
 erase()function return iterator
*/
#include <iostream>
#include <vector>
using namespace std;                                                                                                          
void redundant_if_remove_001() {
	vector<int>vec;
	vector<int>::iterator it = vec.begin();
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	for (; it != vec.end();it++) {
		it = vec.erase(it);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	}
}