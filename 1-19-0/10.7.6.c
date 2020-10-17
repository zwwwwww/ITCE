/*
From:ITC
10
Simple type defects
10.7
int 
10.7.6
 String to int
*/
void int_006() {
	char c[] = "hello";
	int a ;
	itoa(a, c, 10);/*Tool Not should detect this line as error*/ /*ERROR:Simple type error*/
}
