/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.13
" Union of pointer	Constant	 expressions	Write"
*/             
typedef struct {
	int a;
	int b;
} memory_leak_0013_s_001;

typedef struct {
	int a;
	int b;
} memory_leak_0013_s_002;

typedef struct {
	int a;
	int b;
} memory_leak_0013_s_003;

typedef union {
	memory_leak_0013_s_001 *s1;
	memory_leak_0013_s_002 *s2;
	memory_leak_0013_s_003 *s3;
} memory_leak_0013_uni_001;

void memory_leak_0013 ()
{
	memory_leak_0013_uni_001 *u = (memory_leak_0013_uni_001 * )malloc(5*sizeof( memory_leak_0013_uni_001 )); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
	if(u!=NULL)
	{
		u->s1 = (memory_leak_0013_s_001 *) malloc(sizeof(memory_leak_0013_s_001));
	}
	memory_leak_0013_uni_001 *p  = NULL;
	
	if(u!=NULL)
	{
		p = u;
	    p->s1->a = 1;
	    free(u->s1);
	    u->s1 = NULL;
	    free(u);
	}
}
