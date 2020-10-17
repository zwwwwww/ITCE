/*
From:ITC
10
Simple type defects
10.7
int 
10.7.8
Assign other symbols to int
*/
void int_008() {
	int a=#; /*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}