/*
From:ITC
15
Control flow defects
15.9
Ignored return values
15.9.2
ignore int type return value
*/
                                                                                                                           
int func_002(int a, int b) {
	return a * b;
}
void ignored_return_value_002() {
	int a, b;
	scanf("%d %d", &a, &b);
	int c=func_002(a, b);
	printf("%d ", c);/*Tool should Not detect this line as error*/ /*ERROR:Control flow error*/
}
