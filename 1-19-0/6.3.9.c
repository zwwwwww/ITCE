/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.9
single pointer Function arguments
*/
                     
void null_pointer_009_func_001 (int *p)
{
	*p = 1; /*Tool should not detect this line as error*/ /*NO ERROR:NULL pointer dereference*/
}

void null_pointer_009 ()
{
	int buf[5];
	null_pointer_009_func_001(buf);
}
