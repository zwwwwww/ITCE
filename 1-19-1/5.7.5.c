/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.5
Usage of pointers to access array elements
*/
      
extern double dsink;  
void pow_related_errors_005()
{
	double arr[]={2.0,1.2,3.9,8^3800,4.0};
	double* arr1=arr;
	double exponent=2;
	int i;
	double ans;

	for(i=0;i<(sizeof(arr)/sizeof(double));i++)
	{
		double temp=arr1[i];
		ans=pow(temp,exponent); /*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
	}
        dsink = ans;
}