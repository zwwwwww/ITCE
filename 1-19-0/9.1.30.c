/*
From:ITC
9
Static memory defects 
9.1
Static buffer overrun
9.1.30
"1  pointer	int	Also known as double	alias Variable	Write"
*/
                                                                                
extern int sink;                                                                                       
void overrun_st_030 ()
{
	int buf[5];
	int *p1;
	int *p2;
	p1 = buf;
	p2 = p1;
	p2[4] = 1; /*Tool not should detect this line as error*/ /*No ERROR: buffer overrun */
        sink = buf[idx];
}