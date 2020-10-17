/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.2
 Number not a double
*/
         
extern double dsink;       
void pow_related_errors_002()
{
	double num=1.004;
	double exponent=3;
	double ans;
	ans=pow(num,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;

}
