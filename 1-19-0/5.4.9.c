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
	int divisor = 1;
	int ret;
	ret = dividend / divisor; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}
