/*
From:ITC
9
Static memory defects 
9.2
Static buffer underrun 
9.2.10
a decrement in a loop pointer value
*/
                                                                                                   
extern int sink;                                                                                  
int underrun_st_010_gbl_buf[5];
void underrun_st_010 ()
{
	int *p;
	int i;
	p = &underrun_st_010_gbl_buf[4];
	for (i = 0; i < 5; i ++)
	{
		*p = 1; /*Tool should not detect this line as error*/ /*No ERROR:Data Underrun*/
		p --;
	}
}