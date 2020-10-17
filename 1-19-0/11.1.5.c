/*
From:ITC
11
STL defects
11.1
Deref invalid iterator
11.1.5
queue can't use iterator
*/

void invalid_iterator_005() {
	queue<int>q;
	q.push(1);
	q.push(2);
	/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	
}