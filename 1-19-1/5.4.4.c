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
static int zero_division_004_divisor_gbl = 1;
void zero_division_004_func_001 ()
{
	zero_division_004_dividend_gbl %= zero_division_004_divisor_gbl;/*Tool should detect this line as error*/ /* ERROR:division by zero */
}
void zero_division_004 ()
{

	zero_division_004_divisor_gbl--;
	zero_division_004_func_001 ();

}