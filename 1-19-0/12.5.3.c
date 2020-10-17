/*
From:ITC
12
Input/Output defects
12.5
Invalid Printf Arg
12.5.3
Parameter type mismatch(int)
*/

void invalid_printf_arg_003() {
	int c=10;
	printf("%d", c);/*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
}