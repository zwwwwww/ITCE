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
void initialization_008(int expr) {
	switch (expr) {
		int i = 4;/*Tool should detect this line as error*/ /*ERROR:initialization error*/
		f(i);
	case 0:
		i = 17;
		/* Falls through into default code */
	default:
		printf("%d\n", i);
	}
}
