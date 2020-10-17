/*
From:ITC
11
STL defects
11.2
useless calls
11.2.14
The calling function inserts a negative number into a container of type char
*/

using namespace std;	
void useless_call_014() {
	vector<char>v = { 'a','b' };
	v.push_back(-1);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
