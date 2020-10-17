/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.1
 Very high values of number and exponent results in overflow of the answer
*/
       
extern double dsink;      
void pow_related_errors_001()
{

	double num=10^2;
	double exponent=10^2;
	double ans;
	ans=pow(num,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
