/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.12
"int	underflow at	An array of element values"
*/
                                            
extern int sink;                                                   
void data_underflow_012 ()
{
	int min = -2147483647;
	int dlist[4] = {0, 1, -2, -1};
	int ret;
	ret = min - dlist[2]; /*Tool should detect this line as error*/ /*ERROR:Data underflow*/
        sink = ret;
}