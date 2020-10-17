/*
From:ITC
10
Simple type defects
10.4
unsigned
10.4.2
subtraction between two signed int
*/
                                                                                                         
void func_002(unsigned int ui_a, unsigned int ui_b) {
	unsigned int udiff = ui_a - ui_b;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	/* ... */
}
void unsigned_002() {
	unsigned int a;
	unsigned int b;
	printf("输入两个无符号整数:");
	scanf("%d %d", &a, &b);
	func_002(a, b);
}
