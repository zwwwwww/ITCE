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
	p = (int *)(intptr_t)((2 * a) - 6);
	*p = 1;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}