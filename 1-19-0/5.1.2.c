/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.2
"long	Beyond the size of the left shift"
*/
                                                                           
extern int sink;                                                                                            
void bit_shift_002 ()
{
	long a = 1;
	long ret;
	ret = a << 10; /*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
        sink = ret;
}
