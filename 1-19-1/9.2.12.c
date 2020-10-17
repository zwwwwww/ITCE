/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.12
a decrement in a loop pointer value
*/
                                                                            
int underrun_st_012_gbl_buf[5];
void underrun_st_012 ()
{
	int *p;
	p = &underrun_st_012_gbl_buf[4];
	int i=4;
	while(i >= -1)
	{
		*p = 1;/*Tool should detect this line as error*/ /*ERROR:Data Underrun*/
		p --;
		i--;
	}
}

