/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.7
"1 loop	1-Dimensional array"
*/
                                                                                                    
 extern int sink;                                                                                 
void underrun_st_007 ()
{
	int buf[5];
	int i;
	for (i = 4; i > -1; i --)
	{
		buf[i] = 1; /*Tool should not detect this line as error*/ /*No ERROR:Data Underrun*/
	}
        sink = buf[idx];
}