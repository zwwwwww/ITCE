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
	return 0;
}

void zero_division_013 ()
{
	int dividend = 1000;
	int ret;
	ret = dividend / zero_division_013_func_001();/*Tool should detect this line as error*/ /* ERROR:division by zero */
}
