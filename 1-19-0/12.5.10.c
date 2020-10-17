/*
From:ITC
12
Input/Output defects
12.5
Invalid Printf Arg
12.5.10
 Parameter type mismatch(exponent)
*/
                                                                                                                   
void invalid_printf_arg_010() {
	printf("%e", 10000000.0);/*Tool should Not detect this line as error*/ /*ERROR:input/output error*/
}