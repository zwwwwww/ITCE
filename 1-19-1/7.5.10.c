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
	int *ptr = (int*) calloc(5,sizeof(int));
	int *p1 = (int*) calloc(5,sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory Leakage */
	int *p2 = NULL;
	p1 = ptr;
	p2 = p1;
	*(p2+4) = 1;
	free(ptr);
}