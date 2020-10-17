/*
From:ITC
12
Input/Output defects
12.6
Invalid Scanf
12.6.5
The input data is double type and not provide variable address
*/
                                                                                                          
 void invalid_scanf_005() {
	double d;
	scanf("%lf", d);// /*Tool should detect this line as error*/ /*ERROR:input/output error*/
}