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
	double exponent=-2.4;
	double base=-34.50;
	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
