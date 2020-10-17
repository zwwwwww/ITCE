/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.10
using 2 single pointer alias
*/
                              
void memory_leak_0010 ()
{
	int *ptr = (int*) calloc(5,sizeof(int)); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
	int *p1 = NULL;
	int *p2 = NULL;
	if(ptr !=NULL)
	{
	   p1 = ptr;
	   p2 = p1;
	   *(p2+4) = 1;
	   free (ptr);
	}
}
