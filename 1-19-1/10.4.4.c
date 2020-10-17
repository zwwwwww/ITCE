/*
From:ITC
10
Simple type defects
10.4
unsigned
10.4.4
signed overflow can occur even when it seems that only unsigned types are in use
*/
                                                                                                   
void unsigned_004() {
	unsigned short x = 45000, y = 50000;
	unsigned int z = x * y;/*Tool should detect this line as error*/ /*ERROR:Simple type error*/
}
