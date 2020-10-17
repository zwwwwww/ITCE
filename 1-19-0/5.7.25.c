/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.25
Very small negative base and very small odd negative exponent
*/
    
extern double dsink;    
void pow_related_errors_025()
{
	double base=10^3;
	double exponent=0.04;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
