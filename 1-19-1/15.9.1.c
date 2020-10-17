/*
From:ITC
15
Control flow defects
15.9
Ignored return values
15.9.1
ignore bool type return value
*/
                                                                                                      
bool func_001(int a, int b) {
	if (a > b)
		return true;
	else
		return false;
}
int ignored_return_value_001() {
	func_001(1, 2);
	return 0;/*Tool should detect this line as error*/ /*ERROR:Control flow error*/
}
