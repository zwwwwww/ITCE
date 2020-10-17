/*
From:ITC
11
STL defects
11.7
"STL missing comparison
"
11.7.4
The location of the deleted element is not compared with the size of the vector
*/
#include<iostream>	
using namespace std;	
#include<vector>	
void missing_004() {
	vector<int>v(2);
	v[1] = 1;
	v[2] = 2;
	int i;
	scanf(""%d "", &i);
	if (i > 2||i<0) {
		return;
	}
	else
	v.erase(i);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}