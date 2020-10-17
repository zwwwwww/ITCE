/*
From:ITC
12
Input/Output defects
12.6
Invalid Scanf
12.6.2
The input data is char type and not provide variable address
*/
                                                                                                      
void invalid_scanf_002() {
	char c;
	scanf("%c", c );// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}