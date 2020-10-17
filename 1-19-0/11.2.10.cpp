/*
From:ITC
11
STL defects
11.2
useless calls
11.2.10
call pop_back() function in queue
*/
#include<iostream>	
using namespace std;	
#include<queue>
void useless_call_010() {
	queue<int>q;
	q.push(1);
	q.push(2);
	q.pop();/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}