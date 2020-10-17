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
#include<deque>
#include<iostream>
#include<vector>                                                                                                                                                        
void STL_size_004() {
	deque<int>d;
	cout << int(d.size() - 1) << endl; /*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	system("pause");
}