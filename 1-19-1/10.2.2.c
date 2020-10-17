/*
From:ITC
10
Simple type defects
10.2
char
10.2.2
 Character variables can only have one character
*/
                                                                            
void char_002() {
	char m = '197';/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	printf("%c", m);
}
