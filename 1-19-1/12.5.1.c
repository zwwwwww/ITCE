/*
From:ITC
12
Input/Output defects
12.5
Invalid Printf Arg
12.5.1
 Parameter type mismatch(char)
*/
                                                                                                     
 void invalid_printf_arg_001() {
	int a = 3;
	printf("%c ", a);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}