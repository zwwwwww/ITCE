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
	float x = 1.1;
	float y = 2.0;
	f2(x, y);/*Tool should detect this line as error*/ /*ERROR:API error*/
}
