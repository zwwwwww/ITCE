/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.9
/ int variable
*/
        
void zero_division_009 ()
{
	int dividend = 1000;
	int divisor = 0;
	int ret;
	ret = dividend / divisor;/*Tool should detect this line as error*/ /* ERROR:division by zero */
}