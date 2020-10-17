/*
From:ITC
10
Simple type defects
10.2
char
10.2.7
the number of char array too many 
*/
                                                                            
void char_007() {
	char m[2] = { 'a','b','c'};/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	printf("%s", m);
}
