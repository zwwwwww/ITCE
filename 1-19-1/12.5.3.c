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
	char c = "a";
	printf("%d ", c);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}
