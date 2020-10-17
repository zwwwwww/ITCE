/*
From:ITC
10
Simple type defects
10.7
int 
10.7.3
signed int assignment error
*/
void int_003() {
	signed int i = -1;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}