/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.22
 Very small negative base and very small odd negative exponent
*/

extern double dsink;    
void pow_related_errors_022()
{
	double base=-100;
	double exponent=-10^3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
