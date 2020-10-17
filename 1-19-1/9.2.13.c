/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.13
" 1 loop	1-Dimensional array"
*/
                                                                             
int underrun_st_013_gbl_buf[5];
void underrun_st_013 ()
{
	int i=4;
	int var=0;
	while(i >= -1)
	{
		if(var==0)
		underrun_st_013_gbl_buf[i] = 1;/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
	    i--;
	}
}
