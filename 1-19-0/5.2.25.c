/*
From:ITC
5
Numerical defects
5.2
Data over?ow
5.2.25
floating point overflow (double)
*/
            
static int sink;                  
void data_overflow_025 ()
{
	double ret;

	/* 0 11111111110 1111111111111111111111111111111111111111111111111110 */
	double max = 1.7976931348623155e+308;

	/* 0 11111001010 0000000000000000000000000000000000000000000000000000 */
	ret = max + 1.9958403095347198e+292;/*Tool should Not detect this line as error*/ /*No ERROR:Data Overflow*/
        sink = ret;
}
