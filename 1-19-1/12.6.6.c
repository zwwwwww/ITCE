/*
From:ITC
12
Input/Output defects
12.6
Invalid Scanf
12.6.6
The input data is pointer type and not provide variable address
*/
                                                                                                         
void invalid_scanf_006() {
	int* p;
	scanf("%d", *p);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}