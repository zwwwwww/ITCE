/*
From:ITC
12
Input/Output defects
12.7
Invalid Scanf Arg
12.7.1
Parameter type mismatch
*/
                                                                                                     
 void invalid_scanf_arg_001() {
	int i;
	scanf("%c", &i);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}