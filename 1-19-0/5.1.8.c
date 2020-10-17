/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.8
"int	Beyond the size of the left shift	Variable"
*/
                                                                          
extern int sink;                                                                                             
void bit_shift_008 ()
{
	int a = 1;
	int shift = 10;
	int ret;
	ret = a << shift;/*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
        sink = ret;
}
