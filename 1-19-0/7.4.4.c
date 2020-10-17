/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.4
using a pointer to unsigned int based on return value of function
*/
   
#define MAX_VAL 10     
int memory_allocation_failure_004_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = MAX_VAL;
   else
	   ret=1;
   return ret;
}

void memory_allocation_failure_004 ()
{
	unsigned int *ptr = (unsigned int*) malloc(memory_allocation_failure_004_func_001(0)*sizeof(unsigned int)); /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */
	if(ptr !=NULL)
	{
		*(ptr+1) = 10;
		free(ptr);
	}
}
