/*
From:ITC
11
STL defects
11.2
useless calls
11.2.10
call pop_back() function in queue
*/
	
using namespace std;	

void useless_call_010() {
	queue<int>q;
	q.push(1);
	q.push(2);
	q.pop_back();/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
