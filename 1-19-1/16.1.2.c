/*
From:ITC
16
Macros defects
16.1
Constant macros
16.1.2
Change the constant value of macro definition
*/

#define P 1
void constant_macros_002() {
	while (P < 10) {
		P++; /*Tool should detect this line as error*/ /*ERROR:Macros error*/
	}
}

