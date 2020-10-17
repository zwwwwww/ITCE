/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.8
 Large positive base and exponent greater than 1
*/
         
extern double dsink;        
void pow_related_errors_008()
{
	double base=10^3700;
	double exponent=2;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;
}