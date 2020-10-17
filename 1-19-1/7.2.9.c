/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.9
In a variable while loop
*/
     
void free_nondynamic_allocated_memory_009()
{
	char* ptr="s";
	int a=0,b=2;
	while(a<b)
	free(ptr); /*Tool should detect this line as error*/ /*ERROR:Free memory not allocated dynamically*/
}