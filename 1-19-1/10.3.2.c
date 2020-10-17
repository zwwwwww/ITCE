/*
From:ITC
10
Simple type defects
10.3
shift
10.3.2
"Left Shift, signed Type"
*/
void func_002(signed long si_a, signed long si_b) {
	signed long result;
	if (si_a > (LONG_MAX >> si_b)) {/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
		/* Handle error */
	}
	else {
		result = si_a << si_b;
	}
	/* ... */
}
void shift_002() {
	signed long a;
	signed long b;
	printf("输入无符号整数和左移量：");
	scanf("%d %d", &a, &b);
	func_002(a, b);
}
