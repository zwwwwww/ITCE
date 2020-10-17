/*
From:ITC
7
Resource management defects
7.7
Uninitialized memory access
7.7.2
using unsigned long variable - Heap access
*/
    
void uninit_memory_access_002 ()
{
	double *a = (double *) calloc(3,sizeof(double));
	if(a!=NULL)
	{
		a[1] = 10.00000;
	    printf("%lf ",a[1]); /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Memory Access*/
	    free(a);
	}
}