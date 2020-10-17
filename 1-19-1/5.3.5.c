/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.5
"int	Multiply by underflow	Constant"
*/
 
extern int sink;       
void data_underflow_005 ()
{
	int min = -1073741825;	/* 0xbfffffff */
	int ret;
	ret = min * 2;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}