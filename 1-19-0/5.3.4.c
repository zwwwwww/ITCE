/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.4
"int	underflow with -128 Constant"
*/
    
extern int sink;      
void data_underflow_004 ()
{
	int min = -2147483520;
	int ret;
	ret = min - 128; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}
