/*
From:ITC
11
STL defects
11.2
useless calls
11.2.4
Delete iterator point to begin() of empty container
*/

using namespace std;
void useless_call_004() {
	vector<int>v;
	vector<int>::iterator it = v.begin();
	v.erase(it);/*Tool should detect this line as error*/ /*ERROR:STL error*/
	v.push_back(1);
}
