/*
From:ITC
10
Simple type defects
10.1
bool
10.1.6
"Comparison of a function returning boolean value using relational (<, >, <= or >=) operator."
*/
                                                                          
bool f1(int a) {
	if (a > 1)
		return true;
	else
		return false;
}                                                                                                                 
 int bool_005() {
	bool x = f1(0);
	bool y = f1(3);
	if (x == y)/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
		return 0;
	else
		return 1;
}