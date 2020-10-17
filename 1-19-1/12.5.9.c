/*
From:ITC
12
Input/Output defects
12.5
Invalid Printf Arg
12.5.9
There are no parameters
*/
                                                                                                      
void invalid_printf_arg_009() {
	int a = 3;
	printf("%d");/*Tool should detect this line as error*/ /*ERROR:input/output error*/
}
