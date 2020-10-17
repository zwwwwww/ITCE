/*
From:ITC
10
Simple type defects
10.1
bool
10.1.5
"Comparison of two functions returning boolean value using relational (<, >, <= or >=) operator"
*/
                                                                          
bool f(int x, int y) {
	if (x > y) {
		return true;
	}
	else
		return false;
}

bool f1(int a) {
	if (a > 1)
		return true;
	else
		return false;
}                                                                                                                                                                                                                              void bool_004() {
	bool x = f(5, 4);
	bool y = f1(6);
	if (x > y)/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
		return 0;
	else
		return 1;
} 
