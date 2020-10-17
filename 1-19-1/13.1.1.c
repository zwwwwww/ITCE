/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.1
 passed-by-value arg contain uninitialized data
*/
void f1(struct S s) {
	int y = s.x;
	return y;
}                                                                                                                                          
void invalid_function_arg_001() {
	struct S s;
	f1(s);  /*Tool should detect this line as error*/ /*ERROR:API error*/
}
