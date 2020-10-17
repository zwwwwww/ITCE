/*
From:ITC
15
Control flow defects
15.7
uncomplete logic
15.7.1
 if-else logic is uncomplete
*/
                                                                                                       
void uncomplete_logic_001() {
	int a;
	scanf("%d", &a);
	else           /*Tool should detect this line as error*/ /*ERROR:Control flow error*/
	 {
		printf("%d", a);
	}
}
