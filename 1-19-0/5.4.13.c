/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.13
/ return value of function
*/
     
int zero_division_013_func_001 ()
{
	return 1;
}

void zero_division_013 ()
{
	int dividend = 1000;
	int ret;
	ret = dividend / zero_division_013_func_001(); /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}
