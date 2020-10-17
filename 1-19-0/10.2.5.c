/*
From:ITC
10
Simple type defects
10.2
char
10.2.5
signed char
*/
                                                                         
void char_005() {
    char* p = "abcd";/*Tool should Not detect this line as error*/ /*ERROR:Simple type error*/
	printf("%c", p);
}