/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.13
" using a pointer to double in an while  loop, pointer aliasing"
*/
         
#inlude<string.h>                  
void free_null_pointer_013 ()
{
	double * fptr;
	double **fp1 = &fptr;
	double **fp2 = &fptr;
	fptr = NULL;
	int i=0;
	do
	{
		double * fptr = *fp1;
		if(i>=10 && i<=100)
		{
	       fptr = (double *)calloc(10, sizeof(double));
		}
	    *(fptr+3) = 50.5;
	    *fp1 = fptr;
	    i++;
	}while(i>=0 && i<=1);
	do
	{
	    double * fptr = *fp2;
        free(fptr);/* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
        fptr = NULL;
	}while(i>=0 && i<=1);
}