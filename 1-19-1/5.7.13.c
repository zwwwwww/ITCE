/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.13
 Very small negative base and odd exponent greater than 1
*/
       
extern double dsink;       
void pow_related_errors_013()
{
	double base=-0.0000000000000000000000000000000000036;
	double exponent=2000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;
}