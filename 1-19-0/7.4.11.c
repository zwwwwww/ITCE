/*
From:ITC
7
Resource management defects
7.4
Memory allocation failure
7.4.11
"using a pointer to union , with structure as element , memory allocated from other function"
*/
typedef struct {
	int *a;
	int b;
} memory_allocation_failure_011_s_001;

typedef struct {
	int a;
	int b;
} memory_allocation_failure_011_s_002;

typedef struct {
	int a;
	int b;
} memory_allocation_failure_011_s_003;

typedef union {
	memory_allocation_failure_011_s_001 *s1;
	memory_allocation_failure_011_s_002 *s2;
	memory_allocation_failure_011_s_003 *s3;
} memory_allocation_failure_011_uni_001;

int memory_allocation_failure_011_func_001(int flag)
{
   int ret =0;
   if (flag ==0)
	   ret = MAX_VAL;
   else
	   ret=5;
   return ret;
}
memory_allocation_failure_011_uni_001 * memory_allocation_failure_011_gbl_u1;
void memory_allocation_failure_011_func_002(void)
{
	memory_allocation_failure_011_gbl_u1 = (memory_allocation_failure_011_uni_001 * )malloc(memory_allocation_failure_011_func_001(1)*sizeof( memory_allocation_failure_011_uni_001 )); /*Tool should not detect this line as error*/ /*No ERROR:Memory allocation failure */
	memory_allocation_failure_011_gbl_u1->s1 = (memory_allocation_failure_011_s_001 *) malloc(sizeof(memory_allocation_failure_011_s_001));
	memory_allocation_failure_011_gbl_u1->s1->a = (int *) calloc ( 5,sizeof(int));
}
void memory_allocation_failure_011 ()
{
	memory_allocation_failure_011_uni_001 *p =NULL;
	memory_allocation_failure_011_func_002();

	if( memory_allocation_failure_011_gbl_u1 != NULL)
	{
	p = memory_allocation_failure_011_gbl_u1;
	p->s1->a[1] = 10;

	free(memory_allocation_failure_011_gbl_u1->s1->a);
	free(memory_allocation_failure_011_gbl_u1->s1);
	free(memory_allocation_failure_011_gbl_u1);
	}
}
