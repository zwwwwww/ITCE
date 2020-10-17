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
	int buf[5] = {1, 2, 3, 4, 5};
	int *p = buf;
	int ret;
	ret = *p; /*Tool should not detect this line as error*/ /*NO ERROR:NULL pointer dereference*/ 
        sink = ret;
}
