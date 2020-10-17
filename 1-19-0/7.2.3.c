/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.3
 global Inside same  function
*/
            
char *free_nondynamic_allocated_memory_003_gbl_ptr;

void free_nondynamic_allocated_memory_003()
{
	free_nondynamic_allocated_memory_003_gbl_ptr = malloc(sizeof(char));
	free(free_nondynamic_allocated_memory_003_gbl_ptr); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}
