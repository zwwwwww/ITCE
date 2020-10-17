/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.17
"int	Overflow at Nonlinear equation"
*/
        
static int sink;            
void data_overflow_017 ()
{
	int max = 46340;
	int ret;
	ret = (max * max) + 88048; /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}