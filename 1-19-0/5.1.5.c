/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.5
"int	Shift left on negative values"
*/
                                                                           
extern int sink;                                                                                                      
void bit_shift_005 ()
{
	int a = 1;
	int ret;
	ret = a << 10;/*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
        sink = ret;
}
