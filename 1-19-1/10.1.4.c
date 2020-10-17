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
	int x = 3;
	bool y = f(1, 2);
	if (x > y)/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
		printf("%d", x);
	else
		printf("%d", y);
}     
