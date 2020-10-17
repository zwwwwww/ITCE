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
void invalid_function_arg_004() {
	int x = 3;
	int y = 5;
	f2(x, y); /*Tool should  Not detect this line as error*/ /*NO ERROR:API error*/
}
