/*
From:ITC
15
Control flow defects
15.8
Statements with no effects
15.8.6
 else statement has no effects
*/

void statement_with_no_effects_006() {
	int i = 1;
	if (i <10) {
		printf("%d", i);
	}
	else      /*Tool should Not detect this line as error*/ /*ERROR:control flow error*/
		i++;
}

