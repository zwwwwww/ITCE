/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.10
"2-dimensional array	int	Function arguments"
*/

extern int sink;
void uninit_var_010_func_001(int buf[][6])
{
	int ret[5][6] = {{1, 2, 3, 4, 5, 6},
					 {11, 12, 13, 14, 15, 16},
					 {21, 22, 23, 24, 25, 26},
					 {31, 32, 33, 34, 35, 36},
					 {41, 42, 43, 44, 45, 46}};
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 6; j++)
			buf[i][j] = ret[i][j]; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
}

void uninit_var_010()
{
	int buf[5][6];
	uninit_var_010_func_001(buf);
}
