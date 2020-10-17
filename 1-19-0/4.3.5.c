/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.5
"basic types	int	Function arguments"
*/

extern int sink;
int uninit_var_005_func_001(void)
{
	int ret;
	if (1)
		ret = 1;
	return ret; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
}

void uninit_var_005()
{
	int a;
	a = uninit_var_005_func_001();
	sink = a;
}
