/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.1
/int
*/
            
void zero_division_001 ()
{
	int dividend = 1000;
	int ret;
	ret = dividend / 0;/*Tool should detect this line as error*/ /* ERROR:division by zero */
}