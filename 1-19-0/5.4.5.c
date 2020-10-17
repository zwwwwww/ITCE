/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.5
/ 1-D 
*/
               
void zero_division_005 ()
{
	int dividend = 1000;
	int divisors[5] = {2, 1, 3, 0, 4};
	int ret;
	ret = dividend / divisors[2]; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}
