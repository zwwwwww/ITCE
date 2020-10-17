/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.9
using 1 single pointer alias - dangling pointer
*/
             
void memory_leak_009 ()
{
	float *ptr=(float*) malloc(5 * sizeof(float));
	int *p = (int*) malloc(5 * sizeof(int)); /*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	if(ptr !=NULL)
	{
          p = (int *)ptr;
	   *(p+1) = 1.5;
	   free (ptr);
	   ptr = NULL;
	}
}