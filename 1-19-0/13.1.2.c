/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.2
The parameter type passed does not conform to the definition
*/
void f2(int x, int y) {
	int z;
	z = x + y;
	return z;
}
void invalid_function_arg_002() {
	int x = 1;
	int y = 2;
	f2(x, y); /*Tool should  Not detect this line as error*/ /*NO ERROR:API error*/
}
