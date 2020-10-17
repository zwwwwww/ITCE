/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.9
When the base is negative and the exponent is negative
*/

extern double dsink; 
void pow_related_errors_009()
{
	double base=-0.0000000000000000000000000000000000036;
	double exponent=-2;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;
}