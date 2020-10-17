/*
From:ITC
11
STL defects
11.2
useless calls
11.2.12
"After emptying the vector container, delete the tail element"
*/
	
using namespace std;	

void useless_call_012() {
	list<int>l;
	l.push_back(1);
	l.push_back(3);
	l.clear();
	l.pop_back();/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
