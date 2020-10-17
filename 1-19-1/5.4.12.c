/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.12
/ nolinear equation
*/
      
void zero_division_012 ()
{
	int dividend = 1000;
	int divisor = 2;
	int ret;
	ret = dividend / (divisor * divisor - 4);/*Tool should detect this line as error*/ /* ERROR:division by zero */

}