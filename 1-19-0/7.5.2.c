/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.2
using double pointers to the type INT
*/
         
void memory_leak_002 ()
{
	int **ptr = (int**) malloc(5*sizeof(int*));
	int i,j;

	for(i=0;i<5;i++)
		ptr[i]=(int*) malloc(5*sizeof(int)); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			*(*(ptr+i)+j)=i;
		}
	    free(ptr[i]);
	}
	free(ptr);
}
