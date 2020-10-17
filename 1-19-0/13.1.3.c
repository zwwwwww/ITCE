/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.3
There is no parameter passed 
*/
void f2(int x, int y) {
	int z;
	z = x + y;
	return z;
}void invalid_function_arg_003() {

	f2(3, 5); /*Tool should  Not detect this line as error*/ /*NO ERROR:API error*/
}
