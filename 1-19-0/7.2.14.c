/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.14
free a structure pointer
*/
              
typedef struct node1
{
	int a;
	struct node1* next;

}free_nondynamic_allocated_memory_struct_014;
free_nondynamic_allocated_memory_struct_014 * free_nondynamic_allocated_memory_str ;
void free_nondynamic_allocated_memory_014()
{
	free_nondynamic_allocated_memory_str = malloc(sizeof(free_nondynamic_allocated_memory_struct_014));
	free(free_nondynamic_allocated_memory_str); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}
