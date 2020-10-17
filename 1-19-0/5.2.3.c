/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.3
"Overflow in int + 1	Constant"
*/
                                                                                     
static int sink;                                                                                          
void data_overflow_003 ()
{
	int max = 0x7ffffffe;
	int ret;
        // JDR: fixed a signed overflow in next line
	ret = max + 1;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
