/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.26
Large base and large exponent together can lead to overflow
*/
   
extern double dsink;  
void pow_related_errors_026()
{
	double base=10^10;
	double exponent=7000;

	double ans;
	ans=pow(base,exponent);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;
}