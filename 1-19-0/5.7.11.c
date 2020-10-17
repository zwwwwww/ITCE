/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.11
Very small base and exponent greater than 1
*/
                                                                                     
extern double dsink;                                                                              
void pow_related_errors_011()
{
	double exponent=-2.4;
	double base=0.565;
	double ans;
	ans=pow(base,exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
        dsink = ans;
}
