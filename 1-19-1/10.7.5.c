/*
From:ITC
10
Simple type defects
10.7
int 
10.7.5
The calculation result of the unsigned int type variable is assigned to the signed variable
*/
void int_005() {
	unsigned int a = -30;
	unsigned int b = -20;
	signed int c = a + b;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
