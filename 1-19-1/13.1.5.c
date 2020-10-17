/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.5
More parameters than required
*/
void f2(int x, int y) {
	int z;
	z = x + y;
	return z;
}
void invalid_function_arg_003() {

	f2();/*Tool should detect this line as eror*/ /*ERROR: API error*/
}
