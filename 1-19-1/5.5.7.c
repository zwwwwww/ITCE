/*
From:ITC
5
Numerical defects
5.5
Integer precision lost because of cast
5.5.7
unsigned char->unsigned short
*/
 
extern int sink;     
void data_lost_007 ()
{
	unsigned char ret;
	unsigned short a = 0x0100;
	ret = a;/*Tool should detect this line as error*/ /*ERROR:Integer precision lost because of cast*/
        sink = ret;
}