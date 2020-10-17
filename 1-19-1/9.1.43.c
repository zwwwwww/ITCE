/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.43
"for double-loop	Pointer arrays"
*/
                                                                                 
 extern int sink;                                                                                       
void overrun_st_043 ()
{
	int buf1[6];
	int buf2[6];
	int buf3[6];
	int buf4[6];
	int buf5[5];
	int *pbuf[5] = {buf1, buf2, buf3, buf4, buf5};
	int i;
	int j;

	for (i = 0; i < 5; i ++)
	{
		for (j = 0; j < 6; j ++)
		{
			pbuf[i][j] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
		}
	}
}

