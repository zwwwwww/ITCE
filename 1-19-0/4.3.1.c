/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.1
"basic types	int	Variable"
*/

extern int sink;
void uninit_var_001()
{
	int a = 0;
	int ret;
	ret = a; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
	sink = ret;
}
