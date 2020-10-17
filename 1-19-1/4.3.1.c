/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.1
"basic types	int	Variable"
*/

void uninit_var_001()
{
	int a;
	int ret;
	ret = a; /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}
