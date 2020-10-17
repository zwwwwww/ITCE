/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.4
"1-dimensional array	int	Constant	Write"
*/
                                                                                
extern int sink;                                                                                       
void overrun_st_004 ()
{
	int buf[5];
	buf[4] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}