/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.6
Free pointer to different data types
*/
                
void free_nondynamic_allocated_memory_006()
{
	char* ptr1=malloc(sizeof(char));
	int* ptr2=malloc(sizeof(int));
	float* ptr3=malloc(sizeof(float));
	double* ptr4=malloc(sizeof(double));

	free(ptr1);
	free(ptr2);
	free(ptr3);
	free(ptr4); /*Tool should Not detect this line as error*/ /*No ERROR:Free memory not allocated dynamically*/
}
