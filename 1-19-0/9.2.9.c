/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.9
"1 loop	1-Dimensional array"
*/
                                                                                                    
extern int sink;                                                                                    
int underrun_st_009_gbl_buf[5];
void underrun_st_009 ()
{
	int i;
	for (i = 4; i > -1; i --)
	{
		underrun_st_009_gbl_buf[i] = 1; /*Tool should not detect this line as error*/ /*No ERROR:Data Underrun*/
	}
}