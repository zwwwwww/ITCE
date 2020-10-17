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
	int buf[5];
	int **pp;
	int *p = buf;
	pp = &p;
	**pp = 1; /*Tool should not detect this line as error*/ /*NO ERROR:NULL pointer dereference*/
}
