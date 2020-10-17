/*
From:ITC
15
Control flow defects
15.9
Ignored return values
15.9.3
ignore float type return value
*/
float func_003(float a,float b) {
	return a + b;
}

int ignored_return_value_003() {
	func_003(1.1, 2.2);
	return 0;/*Tool should detect this line as error*/ /*ERROR:Control flow error*/
}
