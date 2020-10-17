/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.3
"unsigned int	Beyond the size of the left shift"
*/
           
extern int sink;             
void bit_shift_003 ()
{
	unsigned int a = 1;
	unsigned int ret;
	ret = a << 32;/*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
        sink = ret;
}