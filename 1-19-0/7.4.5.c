/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.5
 using a void pointer  int based on value of global variable inside a switch case statement
*/
   
#define MAX_VAL 10    
void *vptr;
int memory_allocation_failure_005_func_001 (int flag)
{
	switch (flag)
	{
		case 1:
		{
			vptr = (int *)calloc(memory_allocation_failure_005_gbl*memory_allocation_failure_005_gbl, sizeof(int)); /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */
			if(vptr != NULL)
			*((int*)vptr+1) = 10;
			return 1;
		}
		case 2:
		{
			vptr = (char *)calloc(10, sizeof(char));
			if(vptr != NULL)
			*((char*)vptr+2) = 'a';
			return 2;
		}
		case 3:
		{
			vptr = (float *)calloc(10, sizeof(float));
			if(vptr != NULL)
			*((float*)vptr+3) = 5.5;
			return 3;
		}
		default:
			return -1;
	}
}

void memory_allocation_failure_005 ()
{
	int ret;
	ret = memory_allocation_failure_005_func_001 (1);
	if(ret >= 0)
		if(vptr != NULL)
			free(vptr);
}
