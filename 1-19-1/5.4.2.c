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
	dividend /= 0;/*Tool should detect this line as error*/ /* ERROR:division by zero */
	ret = dividend;
}
