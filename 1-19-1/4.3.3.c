/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.3
"2-dimensional array	int	Variable"
*/

void uninit_var_003()
{
	int buf[5][6];
	int ret;
	ret = buf[1][1]; /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/
}
