/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.2
using pointers to the type INT
*/
   
#define MAX_VAL UINT_MAX 
void memory_allocation_failure_002 ()
{
	long long int i=0;
	long long int *ptr=(long long*) malloc(MAX_VAL *sizeof(long long));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure */
	if(ptr !=NULL)
	{
	*(ptr+i) = i;
	free(ptr);
	}
}
