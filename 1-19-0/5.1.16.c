/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.16
"int	Beyond the size of the left shift	Also known as double"
*/
                                                                            
extern int sink;                                                                                                        
void bit_shift_016 ()
{
	int a = 1;
	int shift = 10;
	int shift1;
	int shift2;
	int ret;
	shift1 = shift;
	shift2 = shift1;
	ret = a << shift2;/*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
        sink = ret;
}
