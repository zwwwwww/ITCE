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
	int buf[5] = {1, 2, 3, 4, 5};
	int ret;
	ret = buf[3]; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
	sink = ret;
}
