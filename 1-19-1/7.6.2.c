/*
From:ITC
7
Resource management defects
7.6
Return of a pointer to a local variable
7.6.2
return local variable as function arguments
*/
   
void return_local_002_func_001 (int **pp)
{
	int buf[5];
	*pp = buf;/*Tool should detect this line as error*/ /*ERROR: return -pointer to local variable */
}

void return_local_002 ()
{
	int *p;
	return_local_002_func_001(&p);
	p[3] = 1;
}