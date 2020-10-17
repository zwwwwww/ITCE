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
	ret = a << 10;/*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
        sink = ret;
}
