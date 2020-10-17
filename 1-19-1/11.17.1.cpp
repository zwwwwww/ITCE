/*
From:ITC
11
STL defects
11.17
Erase dereference
11.17.1
Erase acts on reference
*/
#include<list>
using namespace std;
void invalid_iterator()
{
	list<int> a;
	list<int>::iterator i;
	a.push_front(1);
        i=a.begin();
	a.erase(*i);/*Tool should detect this line as error*/ /*ERROR:STL error*/
}