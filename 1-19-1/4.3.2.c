/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.2
"1-dimensional array	int	Variable"
*/

void uninit_var_002()
{
	int buf[5];
	int ret;
	ret = buf[3]; /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}
