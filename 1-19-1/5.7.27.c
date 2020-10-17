/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.27
Small base and large odd exponent together can lead to underflow
*/
        
extern double dsink;        
void pow_related_errors_027()
{
	double base=-100^10;
	double exponent=7000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;
}