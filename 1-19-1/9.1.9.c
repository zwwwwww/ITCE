/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.9
"3-dimensional array	int	Constant	Write"
*/
                                                                                 
extern int sink;                                                                                      
void overrun_st_009 ()
{
	int buf[5][6][7];
	buf[5][5][6] = 1;/*Tool should detect this line as error*/ /*ERROR: buffer overrun */
        sink = buf[idx][idx][idx];
}
