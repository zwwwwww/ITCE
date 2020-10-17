/*
From:ITC
14
Object orientedness defects
0
Initialization
14.7.8
declares variables and contains executable statements before the first case label within the switch statement
*/
                                                                                                               
extern void f(int i) {
	return i;
}
int initialization_008(int expr) {
	/*
	 * Move the code outside the switch block; now the statements
	 * will get executed.
	 */
	int i = 4;/*Tool should Not detect this line as error*/ /*ERROR:initialization error*/
	f(i);

	switch (expr) {
	case 0:
		i = 17;
		/* Falls through into default code */
	default:
		printf("%d\n", i);
	}
	return 0;
}
