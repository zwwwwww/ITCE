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

	/* 0 00000000000 0000000000000000000000000000000000000000000000000010 */
	double min = 9.8813129168249309e-324;

	ret = min / 2.0; /*Tool should Not detect this line as error*/ /*No ERROR:Data Underflow*/
        sink = ret;
}
