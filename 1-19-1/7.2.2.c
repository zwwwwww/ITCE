/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.2
Variable if statement
*/
     
void free_nondynamic_allocated_memory_002()
{
	char* ptr="a";
	int flag=1;
	if(flag>0)
	free(ptr); /*Tool should detect this line as error*/ /*ERROR:Free memory not allocated dynamically*/
}
