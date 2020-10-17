/*
From:ITC
12
Input/Output defects
12.5
Invalid Printf Arg
12.5.2
Parameter type mismatch(unsigned)
*/

void invalid_printf_arg_002() {
	int b = -20;
	printf("%u ", b);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}
