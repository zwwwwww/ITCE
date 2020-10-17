/*
From:ITC
11
STL defects
11.9
"STL if find
"
11.9.1
the value of find in set is not exist
*/
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <string>
using namespace std;                                                                                                        
void STL_if_find_001() {
	set<int> s;
	s.insert(1);
	s.insert(2);
	set<int>::iterator it =s.find(9);  /*Tool should detect this line as error*/ /*ERROR:STL error*/

	if (it != s.end()) {
		cout << *it;
	}
	else
		cout << *it;
}
