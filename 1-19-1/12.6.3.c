/*
From:ITC
12
Input/Output defects
12.6
Invalid Scanf
12.6.3
The input data is string type and not provide variable address
*/
                                                                                                           
void invalid_scanf_003() {
	char s[3];
	scanf("%c", s[0]);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
	scanf("%c", s[1]);
	scanf("%c", s[2]);
}
