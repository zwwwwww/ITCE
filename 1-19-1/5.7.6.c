/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.6
"Usage of a function which returns a very high value 
 causing the result to overflow"
*/
      
extern double dsink;   
double pow_related_errors_006_func_001()
{
	return 10^3800;

}

void pow_related_errors_006()
{
	double exponent=2;	
	double ans;
	ans=pow(pow_related_errors_006_func_001(),exponent); /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
        dsink = ans;

}
