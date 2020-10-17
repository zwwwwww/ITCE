/*
From:ITC
7
Resource management defects
7.2
Free non dynamically allocated memory
7.2.12
 In a if condition statement inside a while loop
*/
void free_nondynamic_allocated_memory_012()
{
	char* ptr="a";
	int a=0,b=2;
	while(a<b)
	{
		a++;
		if(a==1)
		free(ptr); /*Tool should detect this line as error*/ /*ERROR:Free memory not allocated dynamically*/
	}
}
