/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.3
Assign a Constant value to NULL single pointer
*/
            
void null_pointer_003 ()
{
	int **pp;
	int *p = NULL;
	pp = &p;
	**pp = 1;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}