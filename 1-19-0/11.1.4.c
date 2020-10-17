/*
From:ITC
11
STL defects
11.1
Deref invalid iterator
11.1.4
stack can't use iterator
*/

void invalid_iterator_004() {
	stack<int>s;
	s.push(1);
	s.push(2);
	/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	
}