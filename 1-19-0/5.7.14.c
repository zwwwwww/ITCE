/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.14
Very small base and odd exponent greater than 1
*/
       
extern double dsink;        
void pow_related_errors_014()
{
	double base=0.36;
	double exponent=21000;

	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
