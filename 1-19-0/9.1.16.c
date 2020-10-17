/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.16
"1-dimensional array	int	Nonlinear equation	Write"
*/
                                                                                 
extern int sink;                                                                                       
void overrun_st_016 ()
{
	int buf[6];
	int index = 2;
	buf[(index * index) + 1] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}
