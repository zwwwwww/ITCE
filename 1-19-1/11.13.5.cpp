/*
From:ITC
11
STL defects
11.13
"Mismatching containers
"
11.13.5
Sort the elements in an empty list container
*/
#include<iostream>	
using namespace std;	
#include<queue>
#include<vector>	
#include<List>	
void func_005(queue<int>q) {
	q.push(1);
	q.push(2);
}
void mismaching_005() {
	list<int>l;
	func_005(l);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
