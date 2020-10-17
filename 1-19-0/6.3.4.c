/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.4
Assign a Constant value to NULL struct pointer
*/
    
typedef struct {
	int a;
	int b;
	int c;
} null_pointer_004_s_001;

void null_pointer_004 ()
{
	null_pointer_004_s_001 s;
	null_pointer_004_s_001 *p = &s;
	p->a = 1; /*Tool should not detect this line as error*/ /*NO ERROR:NULL pointer dereference*/
}
