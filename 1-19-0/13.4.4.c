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
double abc(double x, double y) {
	return (x + y);
}double wrong_call_004() {

	return abc(1.11, 3.21); /*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
}
