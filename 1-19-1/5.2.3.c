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
	int max = 0x7fffffff;
	int ret;
	ret = max + 1;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}