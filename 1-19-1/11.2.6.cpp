/*
From:ITC
11
STL defects
11.2
useless calls
11.2.6
delete empty map key
*/

using namespace std;	

void useless_call_006() {
	map<int,string>m;
	m.erase(1);/*Tool should detect this line as error*/ /*ERROR:STL error*/
	m[1] = "one";
}
