/*
From:ITC
12
Input/Output defects
12.5
Invalid Printf Arg
12.5.4
Parameter type mismatch(string)
*/
                                                                                                              
 void invalid_printf_arg_004() {
	char c = "a";
	printf("%s ", c);/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}