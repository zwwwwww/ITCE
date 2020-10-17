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
    char* p = "abcd";/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
	printf("%c", p);
}