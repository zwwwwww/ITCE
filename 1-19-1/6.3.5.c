/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.5
Assign a Constant value to NULL union pointer
*/
                
typedef struct {
	int a;
	int b;
} null_pointer_005_s_001;

typedef struct {
	int a;
	int b;
} null_pointer_005_s_002;

typedef struct {
	int a;
	int b;
} null_pointer_005_s_003;

typedef union {
	null_pointer_005_s_001 s1;
	null_pointer_005_s_002 s2;
	null_pointer_005_s_003 s3;
} null_pointer_005_uni_001;

void null_pointer_005 ()
{
	null_pointer_005_uni_001 *p = NULL;
	p->s1.a = 1;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}