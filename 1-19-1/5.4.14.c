/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.14
/ int functiong arg
*/
                 
void zero_division_014_func_001 (int divisor)
{
	int dividend = 1000;
	int ret;
	ret = dividend / divisor;/*Tool should detect this line as error*/ /* ERROR:division by zero */
}

void zero_division_014 ()
{
	zero_division_014_func_001(0);
}