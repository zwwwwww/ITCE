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
	float* p;
	float f = 2.3;
	p = &f;
	printf("%p ", p);/*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
}