/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.8
In a variable while loop which leads to dead code
*/
                            
void free_nondynamic_allocated_memory_008()
{
	char* ptr="b";
	int a=2,b=0;
	while(a<b)
	free(ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}
