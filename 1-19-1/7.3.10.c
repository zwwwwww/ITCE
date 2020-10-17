/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.10
 Memory allocated in a function and Memory used in another function
*/
             
void invalid_memory_access_func_010 (int len ,int **Ptr)
{
	int * p = malloc(sizeof(int) * len);
	*Ptr = p;
}

void invalid_memory_access_010 ()
{
	int ptr[5] = {4,6,9,10,0};
	int *ptr1,i;
	invalid_memory_access_func_010(5,&ptr1);
	for(i=0;i<5;i++)
	{
		*(ptr1+i) = ptr[i];
	}
	free(ptr1);
	*(ptr1+1) = ptr[1];/*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
}