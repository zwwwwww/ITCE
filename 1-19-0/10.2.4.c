/*
From:ITC
10
Simple type defects
10.2
char
10.2.4
char+char=string
*/                                                                          
 void char_004() {
	char m ='¹ú';/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
	printf("%c", m);
}