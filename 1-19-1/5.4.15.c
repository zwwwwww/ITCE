/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.15
/int single alias
*/
                          
void zero_division_015 ()
{
	int dividend = 1000;
	int divisor = 0;
	int divisor1;
	int ret;
	divisor1 = divisor;
	ret = dividend / divisor1;/*Tool should detect this line as error*/ /* ERROR:division by zero */
}