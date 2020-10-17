/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.12
"int	Beyond the size of the left shift	The return value of the function"
*/
int bit_shift_012_func_001 ()
{
	return 10;
}

void bit_shift_012 ()
{
	int a = 1;
	int ret;
	ret = a << bit_shift_012_func_001();/*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
        sink = ret;
}
