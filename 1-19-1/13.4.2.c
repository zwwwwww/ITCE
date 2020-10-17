/*
From:ITC
13
API defects

13.4
Wrong call
13.4.2
function pointer is null
*/
void wrong_call_002() {
	void (*foo)(void);
	foo = 0;
	foo(); /*Tool should detect this line as error*/ /*ERROR:API error*/
}
