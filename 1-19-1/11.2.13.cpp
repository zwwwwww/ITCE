/*
From:ITC
11
STL defects
11.2
useless calls
11.2.13
"After emptying the vector container, delete iterator point "
*/

using namespace std;	
void useless_call_013() {
	list<int>l = { 1,2,3 };
	list<int>::iterator it = l.begin();
	l.clear();
	l.erase(it);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
