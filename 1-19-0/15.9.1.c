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
bool ignored_return_value_001() {
	bool b=func_001(1, 2);
	return b;/*Tool should Not detect this line as error*/ /*ERROR:Control flow error*/
}
