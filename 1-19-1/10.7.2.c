/*
From:ITC
10
Simple type defects
10.7
int 
10.7.2
unsigned int assignment error
*/
void int_002() {
	unsigned int i = 2^32;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
