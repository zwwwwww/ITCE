/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.12
pointr array
*/

void null_pointer_012 ()
{
	int *p = NULL;
	p[3] = 1; /*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}