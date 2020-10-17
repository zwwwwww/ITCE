/*
From:ITC
11
STL defects
11.5
"STL size
"
11.5.1
Vector container out of bounds
*/
#include<iostream>
#include<vector>                                                                                                                              
 int STL_size_001() {
	vector<int> test;
	cout << int(test.size() - 1) << endl; /*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	system("pause");
	return 0;
}