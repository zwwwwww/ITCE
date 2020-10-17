/*
From:ITC
11
STL defects
11.7
"STL missing comparison
"
11.7.3
The start and end positions of the deleted elements are not compared with the size of the vector
*/
#include<iostream>	
using namespace std;	
#include<vector>	
void missing_003() {
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	int i, j;
	scanf(""%d %d"", &i, &j);
	if (i > j || i > 3 || j > 3) {
		return;
	}
	else
	v.erase(i, j);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}
