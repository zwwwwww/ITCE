/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.5
"basic types	int	Function arguments"
*/

int uninit_var_005_func_001(void)
{
	int ret;
	if (0)
		ret = 1;
	return ret; /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}

void uninit_var_005()
{
	int a;
	a = uninit_var_005_func_001();
}
