/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.7
"int	Right shifting negative values with	Constant"
*/
   
extern int sink;         
void bit_shift_007 ()
{
	int a = 1;
	int ret;
	ret = a >> -1;/*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
        sink = ret;
}