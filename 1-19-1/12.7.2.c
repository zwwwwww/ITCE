/*
From:ITC
12
Input/Output defects
12.7
Invalid Scanf Arg
12.7.2
Parameter type mismatch
*/
                                                                                                          
void invalid_scanf_arg_002() {
	char c;
	scanf("%d", &c);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}