/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.4
Insufficient number of paremeter
*/
void f2(int x, int y) {
	int z;
	z = x + y;
	return z;
}
void invalid_function_arg_003() {

	f2(); /*Tool should detect this line as eror ERROR: API error*/
}
