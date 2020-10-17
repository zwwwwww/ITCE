/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.10
"2-dimensional array	int	Function arguments"
*/

void uninit_var_010_func_001(int buf[][6])
{
	int ret[5][6];
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 6; j++)
			buf[i][j] = ret[i][j];
} /*Tool should detect this line as error*/ /*ERROR:Uninitialized Variable*/

void uninit_var_010()
{
	int buf[5][6];
	uninit_var_010_func_001(buf);
}
