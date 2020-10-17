/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.8
"Overflow in unsigned long  + 1	Constant"
*/
                                                                                    
static int sink;                                                                                                   
void data_overflow_008 ()
{
	unsigned long max = 0xfffffffe;
	unsigned long ret;
	ret = max + 1;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
