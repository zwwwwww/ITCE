/*
From:ITC
5
Numerical defects
5.3
Data under?ow
5.3.8
floating point underflow (double)
*/
                 
extern int sink;                     
void data_underflow_008 ()
{
	double ret;

	/* 0 00000000000 0000000000000000000000000000000000000000000000000001 */
	double min = 4.9406564584124654e-324;

	ret = min / 2.0;/*Tool should detect this line as error*/ /*ERROR:Data Underflow*/
        sink = ret;
}
