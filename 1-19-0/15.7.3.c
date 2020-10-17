/*
From:ITC
15
Control flow defects
15.7
uncomplete logic
15.7.3
switch logic is uncomplete
*/

int uncomplete_logic_003() {
	int a;
	scanf("%d", &a);
	switch (a) {
	case 1:
		return a;
		break;
	case 2:
		return a + 1;
		break;
	default:
		break;/*Tool should Not detect this line as error*/ /*ERROR:Control flow error*/
	}
}
