/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.54
cast small data size-large size
*/
                                                                                
 extern int sink;                                                                                      
 int overrun_st_054_buf_gbl[5];
void overrun_st_054 ()
{
	char *p;
	p = (char*)overrun_st_054_buf_gbl;
	*(p + 3) = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
}