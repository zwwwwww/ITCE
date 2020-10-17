/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.4
Usage of double pointers in pow function
*/
          
extern double dsink;     
void pow_related_errors_004()
{
	double arr[]={2.0,1.2,3.9,10^3008,4.0};
	double* arr1=arr;
	double **arr2=&arr1;	
	double exponent=2;
	int i;
	double ans;

	for(i=0;i<5;i++)
	{
		double temp=*(*arr2+i);
		ans=pow(temp,exponent); /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
	}
        dsink = ans;

}