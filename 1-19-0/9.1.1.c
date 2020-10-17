/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.1
" 1-dimensional array	char	Constant	Write"
*/
                                                                                 
extern int sink;                                                                                       
void overrun_st_001 ()
{
	char buf[5];
	buf[4] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}