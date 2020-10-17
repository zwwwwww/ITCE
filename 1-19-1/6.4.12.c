/*
From:ITC
6
Pointer related defects
6.4
Free null pointer
6.4.12
using a pointer to double in an ternary conditional operator
*/
  
#inlude<string.h>           
#define ZERO 0
#define MAX 1
int free_null_pointer_012_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}
void free_null_pointer_012 ()
{
	double *ptr =NULL, a;
	int flag=10;

    if (free_null_pointer_012_func_001(1) == ZERO && MAX ==1)
    {
    	(flag == 10)? (ptr= (double*) malloc(10*sizeof(double))) : ( ptr= NULL);
        (flag == 10)? (*(ptr+1) = 10):(a=100);
    }

    if (free_null_pointer_012_func_001(0) == ZERO && MAX ==1)
    {
    	if(flag == 10)
    	a = *(ptr+1);
    }

    if (free_null_pointer_012_func_001(0) == ZERO && MAX ==1)
    {
    	if(flag == 10)
        {
    		free(ptr); /* Tool should detect this line as error *//*ERROR:Freeing a NULL pointer*/
    	    ptr = NULL;
        }
    }
}