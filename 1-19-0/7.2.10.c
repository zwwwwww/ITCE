/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.10
In a for loop
*/
        
void free_nondynamic_allocated_memory_010()
{
	int i;
	for(i=0;i<1;i++)
	{
		char* ptr=""g"";
		printf(""%s"",ptr);
		/*free(ptr);*/ /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
	}
}
