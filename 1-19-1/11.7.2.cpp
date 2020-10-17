/*
From:ITC
11
STL defects
11.7
"STL missing comparison
"
11.7.2
The position and number of inserts are not compared with the size of the vector
*/
#include<iostream>	
using namespace std;	
#include<vector>	
void missing_002() {
	int pos;
	int n;
	scanf("%d %d", &pos, &n);
	vector<int>v(10);
	v.insert(pos, n, 1);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
