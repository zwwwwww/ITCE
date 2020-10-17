/*
From:ITC
10
Simple type defects
10.4
unsigned
10.4.3
comparison between int and unsigned int
*/
                                                                                                                 
void unsigned_003() {
	int si = -1;
	unsigned int ui = 1;
	printf("%d\n", si < ui);/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
