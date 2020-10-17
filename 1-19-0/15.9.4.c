/*
From:ITC
15
Control flow defects
15.9
Ignored return values
15.9.4
ignore char type return value
*/

char func_004(int a, int b) {
	if (a > b)
		return 'y';
	else
		return 'n';
}
void ignored_return_value_004() {
	char c=func_004(5, 5);/*Tool should Not detect this line as error*/ /*ERROR:Control flow error*/
	printf("%c", c);
}
