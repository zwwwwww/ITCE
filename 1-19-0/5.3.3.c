/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.3
"int	Decrement	-"
*/
                  
extern int sink;                      
void data_underflow_003 ()
{
	int min = -2147483646;	/* 0x80000002 */
	int ret;
	min --;
	min --;
	ret = min; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}
