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
	return 32;
}

void bit_shift_012 ()
{
	int a = 1;
	int ret;
	ret = a << bit_shift_012_func_001();/*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
        sink = ret;
}"