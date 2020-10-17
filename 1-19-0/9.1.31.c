/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.31
" 1 pointer	int	Pointer variables array	-	Constant	Write"
*/
                                                                                
extern int sink;                                                                                       
int overrun_st_031_buf_gbl[5];
void overrun_st_031 ()
{
	int *p;
	p = overrun_st_031_buf_gbl;
	p[4] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
}