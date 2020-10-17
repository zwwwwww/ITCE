/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.2
Assign a Constant value to NULL double pointer
*/
                         
static int sink;                            
void null_pointer_002 ()
{
	int *p = NULL;
	int ret;
	ret = *p;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
        sink = ret;
}
