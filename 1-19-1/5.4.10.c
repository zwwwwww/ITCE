/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.10
/ random
*/
  
int rand(void);          
void zero_division_010 ()
{
	int dividend = 1000;
	int divisor;
	int ret;
	divisor = rand();
	ret = dividend / divisor;/*Tool should detect this line as error*/ /* ERROR:division by zero */
}