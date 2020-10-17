/*
From:ITC
10
Simple type defects
10.2
char
10.2.3
Out of range for char type
*/
                                                                            
void char_003() {
	char m = '中' + '国' + '国' + '国';/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
	printf("%c",m);
}
