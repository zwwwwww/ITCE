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
	float *ptr=(float*) malloc(5 * sizeof(float)); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
	float *p = NULL ;
	if(ptr !=NULL)
	{
	   p = ptr;
	   *(p+1) = 1.5;
	   free (ptr);
	   ptr = NULL;
	}
}
