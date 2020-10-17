/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.13
int variable initialized with function return value using enumeration
*/

typedef enum
{
	ZERO,
	ONE,
	TWO
} values;

int uninit_var_013_func_001(void)
{
	values val; /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
	return val;
}

void uninit_var_013()
{
	int a;
	a = uninit_var_013_func_001();
}
