/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.4
"Overflow in long + 1	Constant"
*/
                                                                                      
static int sink;                                                                                                  
void data_overflow_004 ()
{
	long max = 0x7ffffffe;
	long ret;
	ret = max + 1;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
