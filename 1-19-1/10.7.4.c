/*
From:ITC
10
Simple type defects
10.7
int 
10.7.4
Int type pointer to char type
*/
void int_004() {
	int* p;
	char c = 'a';
	p = c;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
