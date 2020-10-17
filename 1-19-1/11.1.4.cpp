/*
From:ITC
11
STL defects
11.1
Deref invalid iterator
11.1.4
stack can't use iterator
*/
using namespace std;
void invalid_iterator_004() {
	stack<int>s;
	s.push(1);
	s.push(2);
	vector<int>::iterator it;/*Tool should detect this line as error*/ /*ERROR:STL error*/
	for (it = s.top(); it < s.size(); ++it) {
		cout << *it;
	}
}
