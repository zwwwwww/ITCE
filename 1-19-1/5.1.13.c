/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.13
"int	Beyond the size of the left shift	Function arguments"
*/
    
extern int sink;            
void bit_shift_013_func_001 (int shift)
{
	int a = 1;
	int ret;
	ret = a << shift;/*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
        sink = ret;
}

void bit_shift_013 ()
{
	bit_shift_013_func_001(32);
}