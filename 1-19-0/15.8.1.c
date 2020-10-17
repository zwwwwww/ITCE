/*
From:ITC
15
Control flow defects
15.8
Statements with no effects
15.8.1
calling function statement has no effects
*/
                                                                                                                   
int func_001() {
	return 3;
}
void statement_with_no_effects_001() {
	int a = 1, b = 2;
	int c=func_001();/*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
	printf("%d ", a + b+c);
}
