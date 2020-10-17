/*
From:ITC
13
"API defects
"
13.4
Wrong call
13.4.1
function pointer is uninitialized
*/
void wrong_call_001() {
	void (*foo)(void);
	foo();  /*Tool should detect this line as error*/ /*ERROR:API error*/
}
