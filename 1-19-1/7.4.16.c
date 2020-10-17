/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.16
 using a pointer to int 4 pointers
*/
   
#define MAX_VAL 10       
int * memory_allocation_failure_016_gbl_ptr1;
int * memory_allocation_failure_016_gbl_ptr2;

#define MAX_VAL_4 1073741824
int memory_allocation_failure_016_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = MAX_VAL_4;
   else
	   ret=5;
   return ret;
}

void memory_allocation_failure_016_func_002(int flag)
{

   if (flag ==0)
   {
	   ;
   }
   else
   {
	   memory_allocation_failure_016_gbl_ptr1 = (int *) malloc (memory_allocation_failure_016_func_001(0)*sizeof(int));
	   memory_allocation_failure_016_gbl_ptr2 = (int *) malloc (memory_allocation_failure_016_func_001(0)*sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure */
   }

}

void memory_allocation_failure_016 ()
{
	int * ptr1 = (int *) malloc (memory_allocation_failure_016_func_001(0)*sizeof(int));
	int * ptr2 = (int *) malloc (memory_allocation_failure_016_func_001(0)*sizeof(int));
    *(ptr1+1) = 10;
    memory_allocation_failure_016_func_002(0);

    free(memory_allocation_failure_016_gbl_ptr1);
    free(memory_allocation_failure_016_gbl_ptr2);
    free(ptr1);
    free(ptr2);

}