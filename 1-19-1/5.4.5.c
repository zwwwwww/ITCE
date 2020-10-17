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
	int divisors[5] = {2, 1, 0, 3, 4};
	int ret;
	ret = dividend / divisors[2];/*Tool should detect this line as error*/ /* ERROR:division by zero */
}
