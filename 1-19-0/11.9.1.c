/*
From:ITC
11
STL defects
11.9
"STL if find
"
11.9.1
the value of find in set is not exist
*/
void STL_if_find_001() {
	set<int> s;
	s.insert(1);
	s.insert(2);
	set<int>::iterator it = s.find(1);  /*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	if (it != s.end()) {
		cout << *it;
	}
	else
		cout << *it;
}
