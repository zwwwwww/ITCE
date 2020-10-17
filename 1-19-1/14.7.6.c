/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.6
Do not declare a function with an implicit return type
*/

foo(void) {
	return UINT_MAX;
}

int initialization_006(void) {
	long long int c = foo();/*Tool should detect this line as error*/ /*ERROR:initialization error*/
	printf("%lld\n", c);
	return 0;
}
