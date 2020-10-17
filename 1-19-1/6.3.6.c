/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.6
Assign a Value of random variable to NULL single pointer
*/
          
int rand(void);                  
void null_pointer_006 ()
{
	int *p;
	p = (int *)(intptr_t)rand();
	*p = 1;/*Tool should detect this line as error*/ /*ERROR:NULL pointer dereference*/
}
