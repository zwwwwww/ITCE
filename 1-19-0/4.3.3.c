/*
From:ITC
4
Misc defects
4.3
Uninitialized variable 
4.3.3
"2-dimensional array	int	Variable"
*/

extern int sink;
void uninit_var_003()
{
	int buf[5][6] = {{1, 2, 3, 4, 5, 6},
					 {11, 12, 13, 14, 15, 16},
					 {21, 22, 23, 24, 25, 26},
					 {31, 32, 33, 34, 35, 36},
					 {41, 42, 43, 44, 45, 46}};
	int ret;
	ret = buf[1][1]; /*Tool should not detect this line as error*/ /*No ERROR:Uninitialized Variable*/
	sink = ret;
}
