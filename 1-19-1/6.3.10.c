/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.10
single pointer  1 alias 
*/
   
void null_pointer_010 ()
{
	int *p = NULL;
	int *p1;
	p1 = p;
	*p1 = 1;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}
