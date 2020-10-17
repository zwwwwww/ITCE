/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.11
"int	Increment ++ operator"
*/
         
static int sink;             
void data_overflow_011 ()
{
	int max = 0x7fffffff;
	int ret;
	max ++;
	ret = max;/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}