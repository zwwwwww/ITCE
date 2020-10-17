/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.8
using 1 single pointer alias
*/
      
void memory_leak_008 ()
{
	int *ptr=(int*) malloc(5 * sizeof(int)); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
	int *p = NULL ;
	if(ptr !=NULL)
	{
	   p = ptr;
	   *(p+1) = 1;
	   free (ptr);
	   ptr = NULL;
	}
}
