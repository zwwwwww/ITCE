/*
From:ITC
10
Simple type defects
10.3
shift
10.3.3
Right Shift
*/
void func_003(unsigned int ui_a, unsigned int ui_b) {
	unsigned int uresult = ui_a >> ui_b;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	/* ... */
}
void shift_003() {
	unsigned int a;
	unsigned int b;
	printf("输入无符号整数和右移量：");
	scanf("%d %d", &a, &b);
	func_003(a, b);
}
