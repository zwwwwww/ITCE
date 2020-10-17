/*
From:ITC
15
Control flow defects
15.8
Statements with no effects
15.8.3
 expression statement has no effects
*/

int statement_with_no_effects_003() {
	int a = 1, b = 2, c = 0;
	a = a + c;/*Tool should detect this line as error*/ /*ERROR:control flow error*/
	b = b + c;
	return a + b;
}
