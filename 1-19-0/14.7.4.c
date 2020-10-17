/*
From:ITC
14
Object orientedness defects
14.7
Initialization
14.7.4
 the absence of type specifiers in a declaration
*/

extern int fo;
void initialization_004() {
	fo = 3.5;/*Tool should Not detect this line as error*/ /*ERROR:initialization error*/
	printf("%f", foo);
}
