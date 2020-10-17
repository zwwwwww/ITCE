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
	null_pointer_004_s_001 *p = NULL;
	p->a = 1;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}