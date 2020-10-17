/*
From:ITC
11
STL defects
11.1
Deref invalid iterator
11.1.1
Iterator type mismatch
*/

using namespace std;
bool invalid_iterator_001() {
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	vector<unsigned char>::iterator it; /*Tool should detect this line as error*/ /*ERROR:STL error*/
	for (it = v.begin(); it != v.end(); ++it)
		if (*it == 1)return true;
	return false;

}
