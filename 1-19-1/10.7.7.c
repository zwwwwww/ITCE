/*
From:ITC
10
Simple type defects
10.7
int 
10.7.7
Assign string to int
*/
void int_007() {
	int a = "abc";/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
