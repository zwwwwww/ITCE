/*
From:ITC
11
STL defects
11.2
useless calls
11.2.5
clear() a empty vector container
*/

using namespace std;	

void useless_call_005() {
	vector<int>v;
	v.clear();/*Tool should detect this line as error*/ /*ERROR:STL error*/
	v.push_back(1);
}
