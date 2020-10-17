/*
From:ITC
7
Resource management defects
7.6
Return of a pointer to a local variable
7.6.1
return local variable as a function return value
*/
  
int* return_local_001_func_001 ()
{
	int buf[5];
	return buf;/*Tool should detect this line as error*/ /*ERROR: return - pointer to local variable */
}

void return_local_001 ()
{
	int *p;
	p = return_local_001_func_001();
	p[3] = 1;
}