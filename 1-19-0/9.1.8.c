/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.8
"two dimensional array	int	Constant	Write"
*/
                                                                                
extern int sink;                                                                                       
void overrun_st_008 ()
{
	int buf[5][6];
	buf[4][5] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx][idx];
}