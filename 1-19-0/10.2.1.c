/*
From:ITC
10
Simple type defects
10.2
char
10.2.1
Add characters and assigned variables
*/
                                                                          
 void char_001() {
	char m = 'a' + 'b';/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
	printf("%c", m);
}