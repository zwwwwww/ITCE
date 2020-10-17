/*
From:ITC
15
Control flow defects
15.8
Statements with no effects
15.8.2
assignment statement has no effects
*/
                                                               
void statement_with_no_effects_002() {
	int a = 2, b = 3;
	a = 5;/*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
	printf("%d ", a + b);
}
