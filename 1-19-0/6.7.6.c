/*
From:ITC
6
Pointer related defects
6.7
Uninitialized pointer
6.7.6
"double pointer int	Function arguments	Write"
*/
     
extern int sink;        
void uninit_pointer_006_func_001 (int **pp)
{
	**pp = 1; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized pointer*/
}

void uninit_pointer_006 ()
{
	int a =10;
	int *p = &a;
	uninit_pointer_006_func_001(&p);
}
