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

}
void statement_with_no_effects_001() {
	int a = 1, b = 2;
	func_001();/*Tool should detect this line as error*/ /*ERROR:control flow error*/
	printf(""%d "", a + b);
}"
