/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.11
single pointer double alias
*/
 
void null_pointer_011 ()
{
	int *p = NULL;
	int *p1;
	int *p2;
	p1 = p;
	p2 = p1;
	*p2 = 1;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}