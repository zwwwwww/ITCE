/*
From:ITC
10
Simple type defects
10.8
sign
10.8.1
addition between two signed int
*/
                                                                                                      
void func_001(signed int si_a, signed int si_b) {
	signed int sum = si_a + si_b;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
void sign_001() {
	signed int a;
	signed int b;
	ptintf("ÊäÈë·ûºÅÕûÊı£º");
		scanf("%d %d", &a, &b);
		func_001(a, b);
}
