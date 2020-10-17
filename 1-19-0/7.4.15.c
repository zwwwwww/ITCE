/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.15
" using a pointer to int in a goto statement  based on return value function , structure element"
*/
 
#define MAX_VAL 10     
#define MAX_V 10
typedef struct {
	int a;
	int b;
} memory_allocation_failure_015_s_001;

int * memory_allocation_failure_015_gbl_ptr;

int memory_allocation_failure_015_func_001 ()
{
	memory_allocation_failure_015_s_001 s = {MAX_V,20};
	return s.b;
}

void memory_allocation_failure_015_func_002 ()
{
	memory_allocation_failure_015_gbl_ptr = (int *) malloc (memory_allocation_failure_015_func_001()*sizeof(int));/*Tool should detect this line as error*/ /*ERROR:Memory allocation failure */
}

int memory_allocation_failure_015_func_003 (int flag)
{
	int ret = 0;
	if (flag == 1)
	{
		goto my_label;
	}
	return ret;
my_label:
    if (flag == 1)
	{
        memory_allocation_failure_015_func_002();
	}
	*(memory_allocation_failure_015_gbl_ptr+1) = 7;
	ret ++;
	return ret;
}

void memory_allocation_failure_015 ()
{
    int flag;
    flag = memory_allocation_failure_015_func_003(1);
    printf("%d",flag);
}
