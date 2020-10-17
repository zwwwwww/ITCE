/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.10
"int	Underflow at The return value of the function"
*/
                                                       
extern int sink;                                                            
int data_underflow_010_func_001 ()
{
	return 2;
}

void data_underflow_010 ()
{
	int min = -2147483647;
	int ret;
	ret = min - data_underflow_010_func_001(); /*Tool should detect this line as error*/ /*ERROR:Data Under*/
        sink = ret;
}