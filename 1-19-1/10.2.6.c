/*
From:ITC
10
Simple type defects
10.2
char
10.2.6
 unsigned char
*/
                                                                           
 void char_006() {
	unsigned char* p = "abcd";/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	printf("%c", p);
}