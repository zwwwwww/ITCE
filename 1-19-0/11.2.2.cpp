/*
From:ITC
11
STL defects
11.2
useless calls
11.2.2
 insert 0 numbers
*/

using namespace std;	
 useless_call_002() {
	vector<int>v = { 1,2 };
	vector<int>::iterator it = v.end();
	v.insert(it, 2, 1);/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
}