/*
From:ITC
11
STL defects
11.7
"STL missing comparison
"
11.7.1
The insertion position is not compared with the size of the vector
*/
#include<iostream>	
using namespace std;		
#include<vector>
void missing_001() {
	int pos;
	scanf(""%d"", &pos);
	vector<int>v(10);
	if (pos > 10 || pos < 0) {
		return;
	}
	else
	v.insert(pos,1);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}
