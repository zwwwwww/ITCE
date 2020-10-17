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
	for(i=0;i<5;i++)
	{
		char* ptr="l";
		free(ptr); /*Tool should detect this line as error*/ /*ERROR:Free memory not allocated dynamically*/
	}
}