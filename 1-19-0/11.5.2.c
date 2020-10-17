/*
From:ITC
11
STL defects
11.5
"STL size
"
11.5.2
Vector container out of bounds
*/
#include<iostream>
#include<vector>                                                                                                                                      
 void STL_size_002() {
	vector<int> test;
	for (int i = 0; i <= int (test.size()); i++) { /*Tool should Not detect this line as error*/ /*ERROR:STL error*/
		cout << "";
	}
}
