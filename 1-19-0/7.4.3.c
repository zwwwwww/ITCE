/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.3
using double pointers to the type INT
*/
   
#define MAX 10
void memory_allocation_failure_003 ()
{
	unsigned int **ptr = (unsigned int**) malloc(MAX*sizeof(unsigned int*));
	unsigned int i,j;
	if(ptr!=NULL)
	for(i=0;i<MAX;i++)
		ptr[i]=(unsigned int*) malloc(MAX_VAL*sizeof(unsigned int)); /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */

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
