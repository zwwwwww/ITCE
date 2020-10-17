/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.1
 Constant if statement
*/
     
void free_nondynamic_allocated_memory_001()
{
	char* ptr="a";
	if(0)
	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}
