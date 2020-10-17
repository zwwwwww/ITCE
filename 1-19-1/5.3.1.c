/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.1
"int	Underflow with -2	Constant"
*/
                                           
extern int sink;                                          
void data_underflow_001 ()
{
	int min = -2147483647;	/* 0x80000001 */
	int ret;
	ret = min - 2;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}