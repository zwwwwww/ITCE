/*
From:ITC
11
STL defects
11.1
Deref invalid iterator
11.1.8
Iterator usage error
*/
using namespace std;
void invalid_iterator_007() {
	list<int> v;
	list<int>::const_iterator i;
	for (int i = 0; i < v.size(); ++i)/*Tool should detect this line as error*/ /*ERROR:STL error*/
		cout << v[i];
}