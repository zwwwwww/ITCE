/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.4
"unsigned long	Beyond the size of the left shift"
*/
       
extern int sink;            
void bit_shift_004 ()
{
	unsigned long a = 1;
	unsigned long ret;
	ret = a << 32;/*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
        sink = ret;
}