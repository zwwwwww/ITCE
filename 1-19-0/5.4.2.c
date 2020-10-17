/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.2
/=int
*/
                      
void zero_division_002 ()
{
	int dividend = 1000;
	int ret;
	dividend /= 1; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
	ret = dividend;
}
