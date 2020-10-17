/*
From:ITC
11
STL defects
11.9
"STL if find
"
11.9.2
the value of find in list is not exist
*/
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <string>
using namespace std;                                                                                                               
void STL_if_find_002() {
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	list<int>::iterator it = find(l.begin(),l.end(),10);  /*Tool should detect this line as error*/ /*ERROR:STL error*/
	if (it != l.end()) {
		cout << *it;
	}
	else
		cout << *it;
}
