/*
From:ITC
13
"API defects
"
13.4
Wrong call
13.4.2
function pointer is null
*/
void hello() {
	printf("HelloWorld!");
}
void wrong_call_002() {
	void (*foo)(void);
	foo = hello ;
	foo();  /*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
}
