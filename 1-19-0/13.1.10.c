/*
From:ITC
13
API defects 
13.1
Invalid function arg
13.1.10
 Warn on uses of the ¡®getpw¡¯ function
*/
void invalid_function_arg_010() {
	char buff[80];
	getpw(0, buff); /*Tool should Not detect this line as eror*/ /*ERROR: API error*/
}
