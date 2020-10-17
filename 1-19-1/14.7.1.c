/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.1
Differing Storage Durations
*/

const char* p;
void dont_do_this(void) {
	const char c_str[] = "This will change";
	p = c_str; /* Dangerous */ /*Tool should detect this line as error*/ /*ERROR:initialization error*/
}
void innocuous(void) {
	printf("%s\n", p);
}
int initialization_001() {
	dont_do_this();
	innocuous();
	return 0;
}
