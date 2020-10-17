/*
From:ITC
10
Simple type defects
10.8
sign
10.8.2
 subtraction between two signed int
*/
                                                                                               
void func_002(signed int si_a, signed int si_b) {
	signed int diff = si_a - si_b;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	/* ... */
}
void sign_002() {
	signed int a;
	signed int b;
	ptintf("ÊäÈë·ûºÅÕûÊı£º");
	scanf("%d %d", &a, &b);
	func_002(a, b);
}
