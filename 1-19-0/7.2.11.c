/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.11
In a for loop
*/
      
void free_nondynamic_allocated_memory_011()
{
	int i;
	for(i=0;i<0;i++)
	{
		char* ptr="z";
		free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
	}
}
