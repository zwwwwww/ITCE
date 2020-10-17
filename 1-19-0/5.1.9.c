/*
From:ITC
5
Numerical defects
5.1
Bit shift bigger than integral type or negative
5.1.9
"int	Beyond the size of the left shift	Value of random variable"
*/
                                                                           
extern int sink;                                                                                                  
int rand(void);                                                                                                  
void bit_shift_009 ()
{
	int a = 1;
	int shift;
	int ret;
	shift = rand() % 32;
	ret = a << shift;/*Tool should  Not detect this line as error*/ /*NO ERROR:Bit shift error*/
        sink = ret;
}
