/*
From:ITC
6
Pointer related defects
6.3
Dereferencing a NULL pointer
6.3.12
pointr array
*/
   
void null_pointer_012 ()
{
	int buf[5];
	int *p = buf;
	p[3] = 1;
}
