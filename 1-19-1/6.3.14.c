/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.14
 NULL pointer access check after function call
*/
      
int *null_pointer_014_func_001 (void)
{
	return (NULL);
}

void null_pointer_014 ()
{
	int *p;
	p = null_pointer_014_func_001();
	*p = 1; /*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
	if (p != NULL)
	{
		*p = 2;
	}
}