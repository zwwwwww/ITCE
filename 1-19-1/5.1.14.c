/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.14
" int	Beyond the size of the left shift	An array of element values"
*/
                              
extern int sink;                                  
void bit_shift_014 ()
{
	int a = 1;
	int shifts[5] = {8, 40, 16, 32, 24};
	int ret;
	ret = a << shifts[3];/*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
        sink = ret;
}