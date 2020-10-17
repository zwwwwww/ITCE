/*
From:ITC
5
Numerical defects
5.4
Division by zero 
5.4.4
%=int
*/
     
int zero_division_004_dividend_gbl = 1000;
static int zero_division_004_divisor_gbl = 11;
void zero_division_004_func_001 ()
{
	zero_division_004_dividend_gbl %= zero_division_004_divisor_gbl; /*Tool should not detect this line as error*/ /* No ERROR:division by zero */
}
void zero_division_004 ()
{

	zero_division_004_divisor_gbl--;
	zero_division_004_func_001 ();

}