/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.8
"single pointer euqal The return value of the function	expressions"
*/
     
int* null_pointer_008_func_001 ()
{
	return NULL;
}

void null_pointer_008 ()
{
	int *p;
	p = null_pointer_008_func_001();
	*p = 1;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}