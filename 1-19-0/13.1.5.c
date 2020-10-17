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
void invalid_function_arg_005() {
	int y = 2;
	int z = 3;
	f2( y, z); /*Tool should  Not detect this line as error*/ /*NO ERROR:API error*/
}
