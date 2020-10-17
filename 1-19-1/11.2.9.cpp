/*
From:ITC
11
STL defects
11.2
useless calls
11.2.9
Insert int type value to call function in container of type char
*/
	
using namespace std;	

void useless_call_009() {
	stack<int>s;
	s.push_back(1);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
