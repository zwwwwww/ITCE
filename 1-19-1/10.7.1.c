/*
From:ITC
10
Simple type defects
10.7
int 
10.7.1
 unsigned int assignment error
*/
void int_001() {
	unsigned int i=-1;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
