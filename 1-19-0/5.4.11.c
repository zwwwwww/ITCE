/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.11
/ linear equation
*/
         
void zero_division_011 ()
{
	int dividend = 1000;
	int divisor = 2;
	int ret;
	ret = dividend / (2 * divisor - 3); /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}
