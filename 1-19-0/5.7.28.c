/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.28
Small base and very small negative exponent together can lead to overflow
*/
      
extern double dsink;       
void pow_related_errors_028()
{
	double base=-10^2;
	double exponent=-7;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
