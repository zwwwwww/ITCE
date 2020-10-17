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
	unsigned short a = 0xff;
	ret = a;/*Tool should Not detect this line as error*/ /*No ERROR:Integer precision lost because of cast*/
        sink = ret;
}
