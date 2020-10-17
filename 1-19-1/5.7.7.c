/*
From:ITC
5
Numerical defects
5.7
Power related errors
5.7.7
 Usage of an element in the structure which returns a very high value causing the result to overflow
*/
   
extern double dsink;    
typedef struct
{
	double arr[1];
}pow_related_errors_007_s;

void pow_related_errors_007()
{
	double exponent=2;
	double ans;
	double ans1;
	pow_related_errors_007_s* newarr = (pow_related_errors_007_s *)malloc(sizeof(pow_related_errors_007_s));
	pow_related_errors_007_s* ptr_newarr =(pow_related_errors_007_s *)malloc(sizeof(pow_related_errors_007_s));

	newarr->arr[0]=10^3800;
	ptr_newarr->arr[0]=10^3800;

	 ans=pow(newarr->arr[0],exponent);
	 ans1=pow(ptr_newarr->arr[0],newarr->arr[0]);/*Tool should detect this line as error*/ /*ERROR:Data Overflow*/
	free(newarr);
	free(ptr_newarr);
        dsink = ans + ans1;
}