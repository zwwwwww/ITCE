/*
From:ITC
13
"API defects
"
13.4
Wrong call
13.4.4
The returned value of the called function does not match the calling function
*/
int wrong_call_004() {

	return abc(1.11, 3.21);/*Tool should detect this line as error*/ /*ERROR:API error*/
}
