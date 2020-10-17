/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.2
"unsigned int	Underflow with -1	Constant"
*/
               
extern int sink;                     
void data_underflow_002 ()
{
	unsigned int min = 0;
	unsigned int ret;
	ret = min - 1;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}
