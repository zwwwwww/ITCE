/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.13
point to  function
*/
    
int *null_pointer_013_func_001 (void)
{
	return (NULL);
}

void null_pointer_013 ()
{
	int *p;
	p = null_pointer_013_func_001();
	if (p != NULL)
	{
		*p = 1;
	}
	*p = 2;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}