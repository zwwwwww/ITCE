/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.6
"double pointer int	Function arguments	Write"
*/
 
void uninit_pointer_006_func_001 (int **pp)
{
	**pp = 1;/*Tool should detect this line as error*/ /*ERROR:Uninitialized pointer*/
}

void uninit_pointer_006 ()
{
	int a;
	int *p;
	uninit_pointer_006_func_001(&p);
}