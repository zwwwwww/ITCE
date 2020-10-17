/*
From:ITC
10
Simple type defects
10.1
bool
10.1.4
"Comparison of a variable having boolean value using relational (<, >, <= or >=) operator"
*/
                                                                          
 bool f(int x, int y) {
	if (x > y) {
		return true;
	}
	else
		return false;
}                                                                                                                
void bool_003() {
	bool x = true;
	bool y = f(1, 2);
	if (x == y)/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
		printf(""x=y"");
	else
		printf(""x!=y"");
}