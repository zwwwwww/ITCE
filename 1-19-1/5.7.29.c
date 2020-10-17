/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.29
Very Small negative base and very small exponent together can lead to underflow
*/
     
extern double dsink;    
void pow_related_errors_029()
{
	double base=-10^30;
	double exponent=-10^3000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;
}
