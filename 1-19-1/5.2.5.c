/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.5
"Overflow in unsigned char  + 1	Constant"
*/
    
static int sink;        
void data_overflow_005 ()
{
	unsigned char max = 0xff;
	unsigned char ret;
	ret = max + 1;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}