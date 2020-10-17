/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.7
"Overflow in unsigned int  + 1	Constant"
*/
                                                                                     
static int sink;                                                                                        
void data_overflow_007 ()
{
	unsigned int max = 0xfffffffe;
	unsigned int ret;
	ret = max + 1;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
