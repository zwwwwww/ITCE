/*
From:ITC
11
STL defects
11.5
"STL size
"
11.5.3
List container out of bounds
*/
#include<list>
#include<iostream>
#include<vector>                                                                                                                                             
void STL_size_003() {
	list <int> l;
	cout << int(l.size() - 1) << endl; /*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	system("pause");
}