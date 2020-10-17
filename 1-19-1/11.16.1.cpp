/*
From:ITC
11
STL defects
11.16
"Invalid iterator
"
11.16.1
Points to an element that no longer exists
*/
#include<list>
using namespace std;
void invalid_iterator()
{
	list<int> a;
	list<int>::iterator i;
	a.push_front(1);
	a.erase(a.begin());
	i=a.begin();/*Tool should detect this line as error*/ /*ERROR:STL error*/
}
