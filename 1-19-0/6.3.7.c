/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.7
single pointer Linear equation expressions
*/
  
void null_pointer_007 ()
{
	int *p;
	int a = 3;
	p = &a;
	*p = 1; /*Tool should not detect this line as error*/ /*NO ERROR:NULL pointer dereference*/
}
