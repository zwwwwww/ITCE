/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.24
floating point overflow (double)
*/
         
static int sink;              
void data_overflow_024 ()
{
	float ret;

	/* 0 11111110 11111111111111111111110 */
	float max = 3.40282326e+38F;

	/* 0 11100111 00000000000000000000000 */
	ret = max + 2.02824096e+31F;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
