/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.10
"int	Beyond the size of the left shift	Linear equation"
*/
                                                                           
extern int sink;                                                                                                   
void bit_shift_010 ()
{
	int a = 1;
	int shift = 2;
	int ret;
	ret = a << ((5 * shift) + 1);/*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
        sink = ret;
}
