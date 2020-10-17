/*
From:ITC
12
Input/Output defects
12.5
Invalid Printf Arg
12.5.6
Parameter type mismatch(pointer)
*/
                                                                                                         
void invalid_printf_arg_006() {
	float f = 2.3;
	printf("%p ", f);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}