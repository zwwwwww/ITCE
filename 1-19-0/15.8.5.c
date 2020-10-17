/*
From:ITC
15
Control flow defects
15.8
Statements with no effects
15.8.5
while statement has no effects
*/

void statement_with_no_effects_005() {
	int i = 1;
	while (i <10) {/*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
		i++;
	}
}
