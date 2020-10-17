/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.6
Assign a Value of random variable to NULL single pointer
*/
                                             
void null_pointer_006 ()
{
	int a = 20;
	int *p;
	p = &a;
	*p = 1; /*Tool should not detect this line as error*/ /*NO ERROR:NULL pointer dereference*/
}
