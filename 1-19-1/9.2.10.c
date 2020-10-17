/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.10
a decrement in a loop pointer value
*/
                                                                            
int underrun_st_010_gbl_buf[5];
void underrun_st_010 ()
{
	int *p;
	int i;
	p = &underrun_st_010_gbl_buf[4];
	for (i = 0; i <= 5; i ++)
	{
		*p = 1;/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
		p --;
	}
}
