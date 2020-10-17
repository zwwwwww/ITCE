/*
From:ITC
12
Input/Output defects
12.5
Invalid Printf Arg
12.5.5
Parameter type mismatch(float)
*/

void invalid_printf_arg_005() {
	int d = 5;
	printf("%f ", d);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}
