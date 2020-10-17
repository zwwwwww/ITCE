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
	int *ptr=(int*) malloc(5 * sizeof(int));
	int *p = (int*)malloc(5 * sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	if(ptr !=NULL)
	{
	p = ptr;
	*(p+1) = 1;
	free(ptr);
	}
}