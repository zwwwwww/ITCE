/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.16
Very large positive base and odd exponent greater than 1
*/
   
extern double dsink;  
void pow_related_errors_016()
{
	double base=10^36;
	double exponent=20000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;
}