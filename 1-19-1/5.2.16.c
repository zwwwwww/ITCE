/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.16
"int	Overflow at Linear equation"
*/
    
static int sink;         
void data_overflow_016 ()
{
	int max = 429496729;
	int ret;
	ret = (5 * max) + 3; /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        sink = ret;
}