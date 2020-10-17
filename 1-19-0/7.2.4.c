/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.4
 Double pointers
*/
                  
void free_nondynamic_allocated_memory_004()
{
	char* ptr1="a";
	char** ptr=&ptr1;
	while(0)
	free(ptr);  /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}
