/*
From:ITC
11
STL defects
11.5
"STL size
"
11.5.3
deque container out of bounds
*/
#include<iostream>
#include<vector>

using namespace std;
#include<list>
void STL_size_003() {
	list <int> l;
	cout << (l.size() - 1) << endl; /*Tool should detect this line as error*/ /*ERROR:STL error*/
	system("pause");
}