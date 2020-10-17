/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.18
 Very small negative base and very small negative exponent
*/
                 
extern double dsink;            
void pow_related_errors_018()
{
	double base=-10^36;
	double exponent=-10^36;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;
}
