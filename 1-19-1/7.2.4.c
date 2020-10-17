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
	char** ptr;
	char *ptr1 = "STRING";
	ptr = &ptr1;
	free(ptr); /*Tool should detect this line as error*/ /*ERROR:Free memory not allocated dynamically*/
}
