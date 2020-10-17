/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.12
 Very small base and even exponent greater than 1
*/
       
extern double dsink;    
void pow_related_errors_012()
{
	double base=-0.36;
	double exponent=20000;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
