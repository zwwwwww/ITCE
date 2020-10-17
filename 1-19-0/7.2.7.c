/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.7
In a constant while loop
*/
                                 
void free_nondynamic_allocated_memory_007()
{
	char* ptr="a";
	while(0)
	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}
