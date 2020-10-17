/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.1
Assign a Constant value to NULL single pointer
*/

void null_pointer_001 ()
{
	int buf[5];
	int *p = buf;
	*p = 1; /*Tool should not detect this line as error*/ /*NO ERROR:NULL pointer dereference*/
}
