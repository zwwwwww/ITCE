/*
From:ITC
11
STL defects
11.2
useless calls
11.2.1
push_back a null
*/
	
using namespace std;	
void useless_call_001() {
	vector<int>v = { 0 };
	v.push_back();/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
