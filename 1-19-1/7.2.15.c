/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.15
"Global variable , freed in another In a function"
*/
              
char *free_nondynamic_allocated_memory_015_gbl_ptr;
void free_nondynamic_allocated_memory_015_func_001()
{
	free(free_nondynamic_allocated_memory_015_gbl_ptr); /*Tool should detect this line as error*/ /*ERROR:Free memory not allocated dynamically*/
}

void free_nondynamic_allocated_memory_015()
{
	free_nondynamic_allocated_memory_015_gbl_ptr = "STRING";
	free_nondynamic_allocated_memory_015_func_001();
}