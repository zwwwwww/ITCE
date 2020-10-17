/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.15
 Very large negative base and odd exponent greater than 1
*/
   
extern double dsink; 
void pow_related_errors_015()
{
	double base=-10^3600;
	double exponent=21;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;
}