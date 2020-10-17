/*
From:ITC
12
Input/Output defects
12.6
Invalid Scanf
12.6.1
The input data is int type and not provide variable address
*/
                                                                                                           
void invalid_scanf_001() {
	int test;
	scanf("%d", test);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}
