/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.42
"for double-loop	2-Dimensional array"
*/
                                                                                
extern int sink;                                                                                      
void overrun_st_042 ()
{
	int buf[5][6];
	int i;
	int j;
	for (i = 0; i < 5; i ++)
	{
		for (j = 0; j < 6; j ++)
		{
			buf[i][j] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
		}
	}
        sink = buf[idx][idx];
}
