/*
From:ITC
10
Simple type defects
10.8
sign
10.8.6
Unary Negation a signed int
*/
                                                                                                           
void func_006(signed long s_a) {
	signed long result = -s_a;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	/* ... */
}
void sign_006() {
	signed long a;
	printf("ÊäÈë·ûºÅÕûÊý:");
	scanf("%d ", &a);
	func_006(a);
}
