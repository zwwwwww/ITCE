/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.16
/int double alias
*/
        
int *zero_division_016_gbl_divisor ;
void zero_division_016_func_001 ()
{
	zero_division_016_gbl_divisor = malloc(1*sizeof(int));
	*zero_division_016_gbl_divisor= 1;
}
void zero_division_016_func_002 ()
{
	(*zero_division_016_gbl_divisor)++;
}
void zero_division_016 ()
{
	int dividend = 1000;
	int divisor1;
	int divisor2;
	int ret;
	zero_division_016_func_001 ();
	zero_division_016_func_002 ();
	divisor1 = *zero_division_016_gbl_divisor;
	divisor2 = divisor1;
	ret = dividend / divisor2; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}
