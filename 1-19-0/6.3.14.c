/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.14
 NULL pointer access check after function call
*/
    
int null_pointer_014_gbl = 10;
int *null_pointer_014_func_001 (void)
{
	return (&null_pointer_014_gbl);
}

void null_pointer_014 ()
{
	int *p;
	p = null_pointer_014_func_001();
	*p = 1; /*Tool should not detect this line as error*/ /*NO ERROR:NULL pointer dereference*/
	if (p != NULL)
	{
		*p = 2;
	}
}
