/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.6
* Type of defect: memory_allocation_failure - Memory could not be allocated / insufficient memory
*/
 
#define MAX_VAL 10   
#define MAX_10 10
int **memory_allocation_failure_006_gbl_doubleptr;
int memory_allocation_failure_006_func_001(int flag)
{
   int ret;
   if (flag ==0)
	   ret = 0;
   else
	   ret=1;
   return ret;
}

void memory_allocation_failure_006_func_002()
{
	int i;

	if(memory_allocation_failure_006_func_001(0)==0)
	{
		memory_allocation_failure_006_gbl_doubleptr=(int**) malloc(10*sizeof(int*));
    	for(i=0;i<10;i++)
	    {
    		memory_allocation_failure_006_gbl_doubleptr[i]=(int*) malloc(MAX_10*sizeof(int)); /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */
    		memory_allocation_failure_006_gbl_doubleptr[i][0] =10;
	    }
	}
}

void memory_allocation_failure_006()
{
	int flag=0,i;

	if(memory_allocation_failure_006_func_001(flag)==0)
	{
		memory_allocation_failure_006_func_002();
	}
    if(memory_allocation_failure_006_func_001(flag)==0)
	{
		for(i=0;i<10;i++)
		{
			if(memory_allocation_failure_006_gbl_doubleptr[i]!=NULL)
			{
     			free (memory_allocation_failure_006_gbl_doubleptr[i]);
			    memory_allocation_failure_006_gbl_doubleptr[i] = NULL;
			}
	    }
	    free(memory_allocation_failure_006_gbl_doubleptr);
	    memory_allocation_failure_006_gbl_doubleptr = NULL;
	}
}
