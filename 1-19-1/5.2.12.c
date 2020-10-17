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
	int max = 0x7fffff80;
	int ret;
	ret = max + 128;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}
