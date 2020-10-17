/*
From:ITC
11
STL defects
11.1
Deref invalid iterator
11.1.7
" Iterator type mismatch,int¡ª¡ª>char"
*/
                                                                                                                    
bool invalid_iterator_008() {
	vector<char>c;
	c.push_back('a');
	c.push_back('b');
	vector<char>::iterator it = c.begin();/*Tool should Not detect this line as error*/ /*ERROR:STL error*/
	if (*it == 's') {
		return true;
		++it;
	}
	else
		return false;
}