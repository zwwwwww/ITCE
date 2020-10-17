/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.6
" int	Beyond the size of the right shift"
*/
     
extern int sink;         
void bit_shift_006 ()
{
	int a = 1;
	int ret;
	ret = a >> 32;/*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
        sink = ret;
}