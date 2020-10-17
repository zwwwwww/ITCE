/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.12
"int	Overflow + 128	Constant"
*/
                                                                                     
static int sink;                                                                                              
void data_overflow_012 ()
{
	int max = 0x7fffff7f;
	int ret;
	ret = max + 128;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
