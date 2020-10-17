/*
From:ITC
11
STL defects
11.1
Deref invalid iterator
11.1.2
vector use list container iterator
*/

bool invalid_iterator_002() {
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	vector<int>::const_iterator it;/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	for (it = v.begin(); it != v.end(); ++it)
		if (*it == 1)return true;
	return false;

}