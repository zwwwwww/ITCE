/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.19
Very small positive base and very small negative exponent
*/
   
extern double dsink;          
void pow_related_errors_019()
{
	double base=0.0004;
	double exponent=-10^3;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
