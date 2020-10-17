/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.23
the operands is a constant
*/
                  
static int sink;                     
void data_overflow_023 ()
{
	int ret;
	ret = 0x7ffffffe + 1;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
