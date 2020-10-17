/*
From:ITC
12
Input/Output defects
12.6
Invalid Scanf
12.6.4
The input data is float type and not provide variable address
*/
                                                                                                            
void  invalid_scanf_004() {
	float f;
	scanf("%f", f);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}