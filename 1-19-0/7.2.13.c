/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.13
free a structure pointer inside a structure
*/
        
typedef struct node
{
	int a;
	struct node * next;

}free_nondynamic_allocated_memory_struct_013;

void free_nondynamic_allocated_memory_013()
{
	free_nondynamic_allocated_memory_struct_013* new_struct=malloc(sizeof(free_nondynamic_allocated_memory_struct_013));

	new_struct->next = malloc(sizeof(free_nondynamic_allocated_memory_struct_013));
	free(new_struct->next); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
	free(new_struct);
}
