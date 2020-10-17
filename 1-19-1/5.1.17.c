/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.17
the operands is a constant
*/
       
extern int sink;         
void bit_shift_017 ()
{
	int ret;
	ret = 1 << 32;/*Tool should detect this line as error*/ /*ERROR:Bit shift error*/
        sink = ret;
}