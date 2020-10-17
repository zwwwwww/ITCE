/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.3
One of the elements in an array is out of bounds
*/
         
extern double dsink;         
void pow_related_errors_003()
{
	double arr[]={2.0,1.2,3.9,10^3,4.0};
	int i;
	double exponent=2;
	double ans;

	for(i=0;i<(sizeof(arr)/sizeof(double));i++)
	{
		ans=pow(arr[i],exponent); /*Tool should not detect this line as error*/ /*No ERROR:Data Overflow*/
	}
        dsink = ans;
}
