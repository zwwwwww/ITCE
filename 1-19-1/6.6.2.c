/*
From:ITC
6
Pointer related defects
6.6
Comparison NULL with function pointer
6.6.2
constant (number)
*/
         
extern int sink;             
int cmp_funcadr_002_func_001 ()
{
	return 10;
}

void cmp_funcadr_002 ()
{
	int ret = 0;
	if (cmp_funcadr_002_func_001 == NULL)/*Tool should detect this line as error*/ /*ERROR:compare function address with NULL*/
	{
		ret = 1;
	}
        sink = ret;
}