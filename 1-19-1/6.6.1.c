/*
From:ITC
6
Pointe related defects
6.6
Comparison NULL with function pointer
6.6.1
 constant (NULL)
*/
   
extern int sink;       
int cmp_funcadr_001_glb_a;
int* cmp_funcadr_001_func_001 ()
{
	return &cmp_funcadr_001_glb_a;
}

void cmp_funcadr_001 ()
{
	int ret = 0;
	if (cmp_funcadr_001_func_001 == NULL) /*Tool should detect this line as error*/ /*ERROR:compare function address with NULL*/
	{
		ret = 1;
	}
        sink = ret;
}