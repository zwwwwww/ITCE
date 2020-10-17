/*
From:ITC
12
Input/Output defects
12.6
Invalid Scanf
12.6.7
The input data is not define
*/
                                                                                                           
void invalid_scanf_007() {
	scanf("%d", &a);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}