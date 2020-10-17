/*
From:ITC
7
Resource management defects
7.3
Invalid memory access to already freed area
7.3.9
using a Union with structure members - Aliasing
*/
  
typedef union {
	int *a;
	int b;
} invalid_memory_access_009_s_001;

typedef union {
	int a;
	int b;
} invalid_memory_access_009_s_002;

typedef union {
	int a;
	int b;
} invalid_memory_access_009_s_003;

typedef struct {
	invalid_memory_access_009_s_001 *s1;
	invalid_memory_access_009_s_002 s2;
	invalid_memory_access_009_s_003 s3;
} invalid_memory_access_009_uni_001;

void invalid_memory_access_009 ()
{
	invalid_memory_access_009_uni_001 *u = (invalid_memory_access_009_uni_001 * )malloc(5*sizeof( invalid_memory_access_009_uni_001 ));
	invalid_memory_access_009_uni_001 *p  = NULL;

    if(u!=NULL)
    {
	u->s1 = (invalid_memory_access_009_s_001 *) malloc(sizeof(invalid_memory_access_009_s_001));
	if(u->s1!=NULL)
	u->s1->a = (int *) malloc(5*sizeof(int));

	p = u;
	p->s1->a[0] = 1;

	free(u->s1->a);
	free(u->s1);
	free(u);
	p->s1->a[0] = 1; /*Tool should detect this line as error*/ /*ERROR:Invalid memory access to already freed area*/
    }
}