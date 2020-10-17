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
	int b=2;float c=3.5; double d=4.5;
	char* ptr1="a";
	int* ptr2=&b;
	float* ptr3=&c;
	double* ptr4=&d;


	free(ptr4); /*Tool should detect this line as error*/ /*ERROR:Free memory not allocated dynamically*/
}
