/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.13
"int	That overflow in multiplication	Constant"
*/
     
static int sink;          
void data_overflow_013 ()
{
	int max = 0x40000000;
	int ret;
	ret = max * 2;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}