/*
From:ITC
12
Input/Output defects
12.7
Invalid Scanf Arg
12.7.6
Insufficient number of parameters
*/
                                                                                                         
void invalid_scanf_arg_006() {
	int a;
	char b;
	scanf("%d%c", &a);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}
