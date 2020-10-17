/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.16
" Global variable , variable set in another In a function"
*/
                           
char *free_nondynamic_allocated_memory_016_gbl_ptr;
char free_nondynamic_allocated_memory_016_gbl_var;
void free_nondynamic_allocated_memory_016_func_001()
{
	free_nondynamic_allocated_memory_016_gbl_ptr = "STRING";
}

void free_nondynamic_allocated_memory_016_func_002()
{
	if(free_nondynamic_allocated_memory_016_gbl_var =='A')
	   free(free_nondynamic_allocated_memory_016_gbl_ptr);/*Tool should detect this line as error*/ /*ERROR:Free memory not allocated dynamically*/
}

void free_nondynamic_allocated_memory_016()
{
	free_nondynamic_allocated_memory_016_gbl_var = 'A';
	free_nondynamic_allocated_memory_016_func_001();
	free_nondynamic_allocated_memory_016_func_002();
}