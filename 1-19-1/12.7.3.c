/*
From:ITC
12
Input/Output defects
12.7
Invalid Scanf Arg
12.7.3
Parameter type mismatch
*/
                                                                                                            
void invalid_scanf_arg_003() {
	float f;
	scanf("%d", &f);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}
