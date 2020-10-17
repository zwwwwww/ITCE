/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.13
using a double pointer to char in an if condition and memory allocated based on return value of function
*/
  
#define MAX_VAL 10      
static int staticflag=1;
int memory_allocation_failure_013_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = MAX_VAL;
   else
	   ret=5;
   return ret;
}

void memory_allocation_failure_013 ()
{
  // JDR: this function is buggy, commenting it out
#if 0

	char  **dptr,a;
	double *ptr,b = 0.0;
	int i;


    if (staticflag == 10)
    {
    	  	ptr= (double*) malloc(10*sizeof(double));
                if (!ptr) return;
    }
    else
    {
    	  	dptr=(char**) malloc(10*sizeof(char*));
                if (!dptr) return;
    	  	if(1)
    	  	{
            	for(i=0;i<10;i++)
        	    {
            		dptr[i]=(char*) malloc(memory_allocation_failure_013_func_001(0)*sizeof(char)); /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */
                        if (!dptr[i]) return;
        	    }
    	  	}
    }

    if  (staticflag == 10)
    		(*(ptr+1) = 10.5);
    else
    	   strcpy( dptr[1],""STRING TEST"" );

    if(staticflag == 10)
    	b = *(ptr+1);
    else
    	a = dptr[1][1];

    if(staticflag == 10)
    {
    	free(ptr);
    	ptr = NULL;
    }
    else
    {
    	for(i=0;i<10;i++)
    		free(dptr[i]);
    	free(dptr);
    	dptr = NULL;
    }
    printf("%d",a);
    sink = b;

#endif
}
