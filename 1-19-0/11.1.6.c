/*
From:ITC
11
STL defects
11.1
Deref invalid iterator
11.1.6
Iterator usage error 
*/
                                                                                                                           
void invalid_iterator_006() {
	list<int> v;
	list<int>::const_iterator i;
	for (i = v.begin(); i != v.end(); ++i)/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
		cout << *i;
}