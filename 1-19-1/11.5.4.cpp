/*
From:ITC
11
STL defects
11.5
"STL size
"
11.5.4
deque container out of bounds
*/
#include<iostream>
#include<vector>

using namespace std;
#include<list>
include<deque>
void STL_size_004() {
	deque<int>d;
	cout << (d.size() - 1) << endl; /*Tool should detect this line as error*/ /*ERROR:STL error*/
	system("pause");
}