/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.9
"1 loop	1-Dimensional array"
*/
                                                                           
int underrun_st_009_gbl_buf[5];
void underrun_st_009 ()
{
	int i;
	for (i = 4; i >= -1; i --)
	{
		underrun_st_009_gbl_buf[i] = 1;/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
	}
}
