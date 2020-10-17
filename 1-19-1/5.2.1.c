/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.1
"Overflow in char + 1	Constant"
*/
                   
static int sink;                     
void data_overflow_001 ()
{
	char max = 0x7f;
	char ret;
	ret = max + 1;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}