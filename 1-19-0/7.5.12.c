/*
From:ITC
7
Resource management defects
7.5
Memory leakage
7.5.12
" Union of pointer	Constant	 expressions	Write"
*/
           
typedef struct {
	int a;
	int b;
} memory_leak_0012_s_001;

typedef struct {
	int a;
	int b;
} memory_leak_0012_s_002;

typedef struct {
	int a;
	int b;
} memory_leak_0012_s_003;

typedef union {
	memory_leak_0012_s_001 s1;
	memory_leak_0012_s_002 s2;
	memory_leak_0012_s_003 s3;
} memory_leak_0012_uni_001;

void memory_leak_0012 ()
{
	memory_leak_0012_uni_001 *u = (memory_leak_0012_uni_001 * )malloc(5*sizeof( memory_leak_0012_uni_001 )); /*Tool should not detect  this line as error*/ /*No ERROR:Memory Leakage */
	memory_leak_0012_uni_001 *p  = NULL;
	p = u;
    if(u!=NULL)
    {
    	p->s1.a = 1;
	    free(u);
    }
}
