/*
From:ITC
11
STL defects
11.1
Deref invalid iterator
11.1.5
queue can't use iterator
*/
using namespace std;
void invalid_iterator_005() {
	queue<int>q;
	q.push(1);
	q.push(2);
	vector<int>::iterator it;/*Tool should detect this line as error*/ /*ERROR:STL error*/
	for (it = q.front(); it < q.size(); ++it) {
		cout << *it;
	}
}
