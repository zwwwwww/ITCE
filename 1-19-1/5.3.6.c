/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.6
the operands is a constant
*/
   
extern int sink;          
void data_underflow_006 ()
{
	int ret;
	ret = (-2147483647) - 2;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}