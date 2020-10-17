/*
From:ITC
10
Simple type defects
10.3
shift
10.3.1
"Left Shift, Unsigned Type"
*/

void func_001(unsigned int ui_a, unsigned int ui_b) {
	unsigned int uresult = ui_a << ui_b;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	/* ... */
}
void shift_001() {
	unsigned int a;
	unsigned int b;
	printf("输入无符号整数和左移量：");
	scanf("%d %d", &a, &b);
	func_001(a, b);
}
