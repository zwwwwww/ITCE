/*
From:ITC
11
STL defects
11.5
"STL size
"
11.5.2
deque container out of bounds
*/
#include<iostream>
#include<vector>

using namespace std;
void STL_size_002() {
	vector<int> test;
	for (int i = 0; i < (test.size() - 1); i++) { /*Tool should detect this line as error*/ /*ERROR:STL error*/
		cout << "";
	}
}