/*
From:ITC
15
Control flow defects
15.7
uncomplete logic
15.7.4
if-elseif-else logic is uncomplete
*/
                      
void uncomplete_logic_004() {
	int a;
	scanf("%d", &a);
	if (a < 10) {
		a = a + 1;
	}
	else if (a > 10 && a < 20) {
		a = a + 2;
	}/*Tool should detect this line as error*/ /*ERROR:Control flow error*/
	else
		a = a + 3;
}
