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
	double exponent=2;
	double base=-34.50;
	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;

}
