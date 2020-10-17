/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.1
constant shift to the left beyond the int size
*/
             
extern int sink;                  
void bit_shift_001 ()
{
	int a = 1;
	int ret;
	ret = a << 32;/*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
        sink = ret;
}